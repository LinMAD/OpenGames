#include "Ball.h"

namespace SmashBounce
{
    Ball::Ball(const std::string& tagName, const std::string& uuid): Entity(tagName, uuid)
    {
        const auto render = GetRenderer();

        m_Position = Vector2(0, 0);
        m_Speed = Vector2(0, 0);
        m_Radius = 8.0f;
    }

    void Ball::OnUpdate(const float deltaTime)
    {
        Entity::OnUpdate(deltaTime);

        m_Position.x += m_Speed.x * deltaTime;
        m_Position.y += m_Speed.y * deltaTime;

        // Ball collision with screen
        if (m_Position.x <= m_Radius || m_Position.x >= GetRenderer()->GetWidthWithScale() - m_Radius)
        {
            m_Speed.x *= -1;
        }
        if (m_Position.y <= m_Radius || m_Position.y >= GetRenderer()->GetHeightWithScale())
        {
            m_Speed.y *= -1;
        }
    }

    void Ball::OnRender()
    {
        Entity::OnRender();

        DrawCircleV(m_Position, m_Radius, RED);
    }
} // SmashBounce
