#include "ArenaScene.h"

#include <thread>

#include "../Entity/Score.h"
#include "../Game/SmashBounceGame.h"
#include "../Constants/GameTags.h"
#include "../Constants/ColorPicker.h"
#include "Generators/BooleanGenerator.h"

namespace SmashBounce
{
    ArenaScene::ArenaScene(SmashBounceGame& game)
        : m_TimeStarted(Clock::now()), m_Game(game)
    {
        m_GeneratorBool = new OpenGameCore::BooleanGenerator();

        m_Score = CreateEntity<Score>(TAG_SCORE);
        m_PlayersPaddle = CreateEntity<Paddle>(TAG_PLAYER);
        m_PlayersPaddle->AddBall( CreateEntity<Ball>(TAG_PLAYER_BALL));

        NewLevelProgression();
    }

    ArenaScene::~ArenaScene()
    {
        m_BricksCollection.clear();
    }

    void ArenaScene::OnUpdate(const float deltaTime)
    {
        Scene::OnUpdate(deltaTime);

        CollisionCheck();

        if (m_BricksCollection.empty() && !m_LevelCleared)
        {
            m_LevelCleared = true;
            m_levelUpStartTime = std::chrono::steady_clock::now();
        }

        if (m_LevelCleared) // Make delay between level ups
        {
            const auto now = std::chrono::steady_clock::now();
            const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                now - m_levelUpStartTime
            ).count();

            if (elapsed >= m_LevelUpDelay)
            {
                m_LevelCleared = false;
                m_Score->CalculateLevelBonus();

                NewLevelProgression();
            }
        }

        const auto rend = GetRenderer();
        m_TimeElapsedText = "Smash Time: " + std::to_string(static_cast<int>(GetPlayerLevelPlayTime())) + "s";
        m_TimeElapsedTextWidth = MeasureText(m_TimeElapsedText.c_str(), m_TimeElapsedTextHeight);
        m_TimeElapsedTextPosition = Vector2{(rend->GetWidthWithScale() / 2.f - static_cast<float>(m_TimeElapsedTextHeight * 2)),0.f};
    }

    void ArenaScene::OnRender()
    {
        Scene::OnRender();

        const auto rend = GetRenderer();
        rend->RenderTextWithFont(
            m_TimeElapsedText.c_str(),
            static_cast<int>(m_TimeElapsedTextPosition.x),
            static_cast<int>(m_TimeElapsedTextPosition.y),
            m_TimeElapsedTextHeight,
            COLOR_PICKER_LIGHT_BLUE
        );

        if (m_LevelCleared)
        {
            rend->RenderTextWithFont(
                M_LEVEL_UP_TEXT.c_str(),
                static_cast<int>(rend->GetWidthWithScale()) / 2 - 30,
                static_cast<int>(rend->GetHeightWithScale()) / 2 - 30,
                30,
                COLOR_PICKER_RED
            );
        }
    }

    void ArenaScene::NewLevelProgression()
    {
        if (m_LevelCleared) return; // Allow level gen when will be false

        // TODO (LinMAD): Add animation for block generation later
        for (int i = 0; i < M_BRICK_ROWS; ++i)
        {
            for (int j = 0; j < M_BRICK_COLUMNS; ++j)
            {
                const auto blockSimple = CreateEntity<BlockSimple>(
                    "BlockSimple_" + std::to_string(i) + "_" + std::to_string(j)
                );

                blockSimple->SetLeftCornerLocation(Vector2(static_cast<float>(j), static_cast<float>(i)));
                m_BricksCollection.push_back(blockSimple);
            }
        }

        const auto playerMarbles = FindEntitiesByName<Ball>(TAG_PLAYER_BALL);
        for (const auto& marble : playerMarbles)
        {
            marble->SetNewBaseSpeedMutator(static_cast<float>(m_Score->GetCurrentLevel()));
        }
    }

    float ArenaScene::GetPlayerLevelPlayTime() const
    {
        return std::chrono::duration<float>(Clock::now() - m_TimeStarted).count();
    }

    // TODO (LinMAD): Refactor logic for ball bounce walls => Bug stuck in the wall
    // TODO (LinMAD): Refactor logic for ball and paddle => tunneling issue
    void ArenaScene::CollisionCheck()
    {
        // Check if player catch a ball?
        const auto paddleShape = m_PlayersPaddle->GetShape();
        const auto playerMarbles = FindEntitiesByName<Ball>(TAG_PLAYER_BALL);
        for (size_t i = 0; i < playerMarbles.size(); ++i)
        {
            const auto& currentMarble = playerMarbles[i];
            handleMarbleCollisionWithPlayerPaddle(paddleShape, currentMarble);

            // Check if player managed hit bricks
            for (auto it = m_BricksCollection.begin(); it != m_BricksCollection.end();)
            {
                auto const& brick = *it;
                auto const isBallCollidingWithBrick = CheckCollisionCircleRec(
                    currentMarble->GetPosition(),
                    currentMarble->GetRadius(),
                    brick->GetShape()
                );

                if (m_LevelCleared) return;

                if (brick->IsAlive() && isBallCollidingWithBrick)
                {
                    auto newSpeed = currentMarble->GetVelocity();
                    newSpeed.y *= -1;

                    currentMarble->SetNewVelocity(newSpeed);

                    // TODO (LinMAD): Improve better of pickups spawn logic maybe with score or block count so it will be more interesting
                    if (playerMarbles.size() < 3)
                    {
                        const bool isPickupItemMarblesExist = FindFirstEntityByName<PickupItemMarbles>(TAG_PICKUP_MARBLES) != nullptr;
                        if (!isPickupItemMarblesExist && m_GeneratorBool->GetRandomBool())
                        {
                            m_PickupItemMarbles = CreateEntity<PickupItemMarbles>(TAG_PICKUP_MARBLES);
                            m_PickupItemMarbles->SetNewPosition(brick->GetPosition());
                        }
                        else if (isPickupItemMarblesExist && !m_PickupItemMarbles->GetIsActive() && m_GeneratorBool->
                            GetRandomBool())
                        {
                            m_PickupItemMarbles->SetActive(true);
                            m_PickupItemMarbles->SetNewPosition(brick->GetPosition());
                        }
                    }

                    brick->SetAlive(false);
                    DestroyEntity(brick);

                    m_BricksCollection.erase(it);
                    FindFirstEntityByName<Score>(TAG_SCORE)->AddPoints(brick->GetScorePoints());

                    break;
                }

                ++it;
            }

            // Is player managed pickup item?
            if (m_PickupItemMarbles != nullptr)
            {
                const auto isMarblesPickedUp = CheckCollisionCircleRec(
                    m_PickupItemMarbles->GetPosition(),
                     m_PickupItemMarbles->GetRadius(),
                    m_PlayersPaddle->GetShape()
                );

                if (isMarblesPickedUp && currentMarble != nullptr)
                {
                    if (playerMarbles.size() < 3 && m_PickupItemMarbles->GetIsActive())
                    {
                        const auto newMarble = CreateEntity<Ball>(TAG_PLAYER_BALL);
                        newMarble->SetNewPosition(currentMarble->GetPosition());
                        newMarble->SetNewVelocity(Vector2(currentMarble->GetVelocity().x + 10, currentMarble->GetVelocity().y + 10));
                    }

                    m_PickupItemMarbles->SetActive(false); // picked
                }
            }
        }
    }

    void ArenaScene::handleMarbleCollisionWithPlayerPaddle(const Rectangle paddleShape, const std::shared_ptr<Ball>& marble)
    {
        if (marble == nullptr) return;

        const auto ballPosition = marble->GetPosition();
        const auto ballRadius = marble->GetRadius();
        auto ballSpeed = marble->GetVelocity();

        const auto isBallCollidingWithPaddle = CheckCollisionCircleRec(ballPosition, ballRadius, paddleShape);
        const auto isSideCollisionWithPaddle = (
            ballPosition.x + ballRadius >= paddleShape.x && ballPosition.x - ballRadius <= paddleShape.x
        ) || (
            ballPosition.x - ballRadius <= paddleShape.x + paddleShape.width && ballPosition.x + ballRadius >=
            paddleShape.x + paddleShape.width
        );

        if (isBallCollidingWithPaddle)
        {
            // Handle Top Surface Collision
            if (ballPosition.y + ballRadius > paddleShape.y && ballSpeed.y > 0)
            {
                // Reposition ball to prevent sticking - place just above the paddle
                marble->SetNewPosition({ballPosition.x, paddleShape.y - ballRadius - 1});

                // Calculate relative hit position
                const float paddleCenter = paddleShape.x + paddleShape.width / 2.0f;
                const float relativeHitPosition = (ballPosition.x - paddleCenter) / (paddleShape.width / 2.0f);

                // Adjust horizontal speed for deflection
                ballSpeed.x += relativeHitPosition * 200.0f; // Adjust deflection angle
                // Prevent extreme values
                ballSpeed.x = std::clamp(ballSpeed.x, -400.0f, 400.0f);
                ballSpeed.y = -std::abs(ballSpeed.y); // Ensure it bounces upward
            }
            else if (isSideCollisionWithPaddle)
            {
                ballSpeed.x *= -1; // Reverse horizontal speed
            }

            marble->SetNewVelocity(ballSpeed);
        }
    }
} // SmashBounce
