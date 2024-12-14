#include "ArenaScene.h"

#include "../Game/SmashBounceGame.h"

namespace SmashBounce
{
    ArenaScene::ArenaScene(SmashBounceGame& game): m_Game(game)
    {
        m_PlayersPaddle = CreateEntity<Paddle>(m_Game.TAG_PLAYER);
        m_PlayersBall = CreateEntity<Ball>(m_Game.TAG_PLAYER_BALL);
        m_Score = FindEntityByName<Score>(m_Game.TAG_SCORE);

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

        if (m_BricksCollection.empty())
        {
            m_SceneCleared = true;
        }
    }

    void ArenaScene::OnRender()
    {
        Scene::OnRender();

        // TODO (LinMAD): Add level up message
    }

    void ArenaScene::NewLevelProgression()
    {
        m_SceneCleared = false;

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
    }

    void ArenaScene::CollisionCheck()
    {
        // Check if player catch a ball?
        const auto ballPosition = m_PlayersBall->GetPosition();
        const auto ballRadius = m_PlayersBall->GetRadius();
        const auto paddleShape = m_PlayersPaddle->GetShape();
        auto ballSpeed = m_PlayersBall->GetSpeed();

        const auto isBallCollidingWithPaddle = CheckCollisionCircleRec(ballPosition, ballRadius, paddleShape);
        const auto isSideCollisionWithPaddle = (
            ballPosition.x + ballRadius >= paddleShape.x && ballPosition.x - ballRadius <= paddleShape.x
        ) || (
            ballPosition.x - ballRadius <= paddleShape.x + paddleShape.width && ballPosition.x + ballRadius >= paddleShape.x + paddleShape.width
        );

        if (isBallCollidingWithPaddle)
        {
            // Handle Top Surface Collision
            if (ballPosition.y + ballRadius > paddleShape.y && ballSpeed.y > 0)
            {
                // Reposition ball to prevent sticking - place just above the paddle
                m_PlayersBall->SetNewPosition({ballPosition.x, paddleShape.y - ballRadius - 1});

                // Calculate relative hit position
                const float paddleCenter = paddleShape.x + paddleShape.width / 2.0f;
                const float relativeHitPosition = (ballPosition.x - paddleCenter) / (paddleShape.width / 2.0f);
                // -1 to +1

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

            m_PlayersBall->SetNewSpeed(ballSpeed);
        }

        if (m_SceneCleared) return;

        // Check if player managed hit bricks
        for (auto it = m_BricksCollection.begin(); it != m_BricksCollection.end();)
        {
            auto const& brick = *it;
            auto const isBallCollidingWithBrick = CheckCollisionCircleRec(
                m_PlayersBall->GetPosition(),
                m_PlayersBall->GetRadius(),
                brick->GetShape()
            );

            if (brick->IsAlive() && isBallCollidingWithBrick)
            {
                auto newSpeed = m_PlayersBall->GetSpeed();
                newSpeed.y *= -1;

                m_PlayersBall->SetNewSpeed(newSpeed);

                brick->SetAlive(false);
                DestroyEntity(brick);
                m_BricksCollection.erase(it);
                FindEntityByName<Score>(m_Game.TAG_SCORE)->AddPoints(brick->GetScorePoints());

                break;
            }

            ++it;
        }
    }
} // SmashBounce
