#include "SmashBounce.h"

#include "../Entity/BlockSimple.h"
#include "../Entity/Paddle.h"

// TODO (LinMAD): Add UI
// TODO (LinMAD): Add Score system + add speed to the ball
// TODO (LinMAD): Replace shapes by textures

namespace SmashBounce
{
    SmashBounceGame::SmashBounceGame()
    {
        m_SceneArena = ArenaScene();

        m_Player = m_SceneArena.CreateEntity<Paddle>(m_TagPlayer);
        m_PlayersBall = m_SceneArena.CreateEntity<Ball>(m_TagBall);

        for (int i = 0; i < m_BrickRows; ++i) {
            for (int j = 0; j < m_BrickColumns; ++j) {
                const auto blockSimple = m_SceneArena.CreateEntity<BlockSimple>(
                    "BlockSimple_" + std::to_string(i) + "_" + std::to_string(j)
                );
                blockSimple->SetLeftCornerLocation(Vector2(j, i));
                m_BricksCollection.push_back(blockSimple);
            }
        }

        // TODO Add UI
        m_SceneArena.ToggleIsPaused();
    }

    SmashBounceGame::~SmashBounceGame()
    {
        m_SceneArena.DestroyEntity(m_Player);
        m_SceneArena.DestroyEntity(m_PlayersBall);

        m_BricksCollection.clear();
    }

    void SmashBounceGame::OnUpdate(const float deltaTime)
    {
        AbstractGameInstance::OnUpdate(deltaTime);

        { // Game Pause or Over
            if (m_IsGameOver)
            {
                GetRenderer()->RenderText("Game Over", 250, 150, 60, 0x0000ffd3);
                return;
            }
            if (m_SceneArena.IsPaused()) return;
        }

        // Update game world
        m_SceneArena.OnUpdate(deltaTime);

        { // Collision checks
            if (m_PlayersBall->GetPosition().y > GetRenderer()->GetHeight()) {
                m_IsGameOver = true;
                return;
            }

            // TODO (LinMAD): Investigate why ball bouncing under paddle
            const auto isBallCollidingWithPaddle = CheckCollisionCircleRec(
                m_PlayersBall->GetPosition(),
                m_PlayersBall->GetRadius(),
                m_Player->GetShape()
            );
            if (isBallCollidingWithPaddle)
            {
                auto newSpeed = m_PlayersBall->GetSpeed();
                newSpeed.y *= -1;

                m_PlayersBall->SetNewSpeed(newSpeed);
            }

            // Ball collision with bricks
            for (const auto& brick : m_BricksCollection) {
                auto const isBallCollidingWithBrick = CheckCollisionCircleRec(
                    m_PlayersBall->GetPosition(),
                    m_PlayersBall->GetRadius(),
                    brick->GetShape()
                );

                if (brick->IsAlive() && isBallCollidingWithBrick) {
                    auto newSpeed = m_PlayersBall->GetSpeed();
                    newSpeed.y *= -1;

                    m_PlayersBall->SetNewSpeed(newSpeed);

                    brick->SetAlive(false);
                    m_SceneArena.DestroyEntity(brick);

                    break;
                }
            }
        }
    }

    void SmashBounceGame::OnRender()
    {
        AbstractGameInstance::OnRender();

        m_SceneArena.OnRender();
    }
} // Template
