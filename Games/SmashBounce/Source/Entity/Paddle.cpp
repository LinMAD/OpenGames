#include "Paddle.h"

namespace SmashBounce
{
    Paddle::Paddle(const std::string& tagName, const std::string& uuid) : Entity(tagName, uuid)
    {
        Init();
    }

    void Paddle::Init()
    {
        m_PaddleRect = Rectangle{
            static_cast<float>(GetRenderer()->GetWidth()) / 2 - 50,
            static_cast<float>(GetRenderer()->GetHeight()) - 20,
            100,
            10
        };
    }

    void Paddle::OnUpdate(const float deltaTime)
    {
        Entity::OnUpdate(deltaTime);

        { // Handle movement
            const auto isMoveLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
            const auto isMoveRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);

            if (isMoveLeft && m_PaddleRect.x > 0) {
                m_PaddleRect.x -= m_PaddleSpeed * deltaTime;
            }
            // TODO (LinMAD): Investigate issue with right side inv wall
            if (isMoveRight && m_PaddleRect.x + m_PaddleRect.width < static_cast<float>(GetRenderer()->GetWidth())) {
                m_PaddleRect.x += m_PaddleSpeed * deltaTime;
            }
        }
    }

    void Paddle::OnRender()
    {
        Entity::OnRender();

        DrawRectangleRec(m_PaddleRect, BLACK);
    }
} // SmashBounce
