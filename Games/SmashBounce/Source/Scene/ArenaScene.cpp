#include "ArenaScene.h"

#include "../Game/SmashBounce.h"

namespace SmashBounce
{
    ArenaScene::ArenaScene(SmashBounceGame& game): m_Game(game)
    {
        m_PlayersPaddle = CreateEntity<Paddle>(m_Game.m_TagPlayer);
        m_PlayersBall = CreateEntity<Ball>(m_Game.m_TagPlayerBall);

        for (int i = 0; i < m_BrickRows; ++i)
        {
            for (int j = 0; j < m_BrickColumns; ++j)
            {
                const auto blockSimple = CreateEntity<BlockSimple>(
                    "BlockSimple_" + std::to_string(i) + "_" + std::to_string(j)
                );

                blockSimple->SetLeftCornerLocation(Vector2(static_cast<float>(j), static_cast<float>(i)));
                m_BricksCollection.push_back(blockSimple);
            }
        }
    }

    ArenaScene::~ArenaScene()
    {
        m_BricksCollection.clear();
    }

    void ArenaScene::OnUpdate(const float deltaTime)
    {
        Scene::OnUpdate(deltaTime);

        // Check if player catch a ball?
        const auto isBallCollidingWithPaddle = CheckCollisionCircleRec(
            m_PlayersBall->GetPosition(),
            m_PlayersBall->GetRadius(),
            m_PlayersPaddle->GetShape()
        );
        if (isBallCollidingWithPaddle)
        {
            auto newSpeed = m_PlayersBall->GetSpeed();
            newSpeed.y *= -1;

            m_PlayersBall->SetNewSpeed(newSpeed);
        }

        // Check if player managed hit bricks
        for (auto it = m_BricksCollection.begin(); it != m_BricksCollection.end(); )
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

                break;
            }

            ++it;
        }
    }

    void ArenaScene::OnRender()
    {
        Scene::OnRender();
    }
} // SmashBounce
