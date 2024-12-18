#include "Paddle.h"

namespace SmashBounce
{
    Paddle::Paddle(const std::string& tagName, const std::string& uuid) : Entity(tagName, uuid)
    {
        m_IsInitialPlayPaddle = true;
        m_PaddleRect = Rectangle{
            GetRenderer()->GetWidthWithScale() / 2 - 50,
            GetRenderer()->GetHeightWithScale() - 20,
            100,
            50
        };
    }

    void Paddle::OnUpdate(const float deltaTime)
    {
        Entity::OnUpdate(deltaTime);

        // Handle movement
        const auto isMoveLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
        const auto isMoveRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);

        if (isMoveLeft && m_PaddleRect.x > 0)
        {
            m_PaddleRect.x -= m_PaddleSpeed * deltaTime;
        }
        // TODO (LinMAD): Investigate issue with right side inv wall
        if (isMoveRight && m_PaddleRect.x + m_PaddleRect.width < GetRenderer()->GetWidthWithScale())
        {
            m_PaddleRect.x += m_PaddleSpeed * deltaTime;
        }

        // Serve the ball
        const auto isServeButtonPressed = IsKeyReleased(KEY_SPACE);
        if (m_IsInitialPlayPaddle)
        {
            m_PlayersBall->SetNewPosition(Vector2{m_PaddleRect.x + m_PaddleRect.width / 2, m_PlayersBall->GetPosition().y});
        }
        if (isServeButtonPressed)
        {
            m_IsInitialPlayPaddle = false;
            m_PlayersBall->SetNewSpeed(Vector2{0, -200.0f});
        }
    }

    void Paddle::OnRender()
    {
        Entity::OnRender();

        DrawRectangleRec(m_PaddleRect, BLACK);
    }

    void Paddle::AddBall(const std::shared_ptr<Ball>& ball)
    {
        m_PlayersBall = ball;
        m_PlayersBall->SetNewPosition(Vector2{
            m_PaddleRect.x + m_PaddleRect.width / 2,
            m_PaddleRect.y - m_PlayersBall->GetRadius()}
        );
    }
} // SmashBounce
