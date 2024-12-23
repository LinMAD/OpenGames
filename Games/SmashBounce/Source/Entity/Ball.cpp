#include "Ball.h"

#include <raymath.h>

namespace SmashBounce
{
    Ball::Ball(const std::string& tagName, const std::string& uuid): Entity(tagName, uuid)
    {
        const auto render = GetRenderer();

        m_Position = Vector2(0, 0);
        m_Velocity = Vector2(0, 0);
        m_Radius = 8.0f;
    }

    void Ball::OnUpdate(const float deltaTime)
    {
        Entity::OnUpdate(deltaTime);

        m_Position.x += m_Velocity.x * deltaTime;
        m_Position.y += m_Velocity.y * deltaTime;

        // Ball collision with screen
        if (m_Position.x <= m_Radius || m_Position.x >= GetRenderer()->GetWidthWithScale() - m_Radius)
        {
            m_Velocity.x *= -1;
        }
        if (m_Position.y <= m_Radius || m_Position.y >= GetRenderer()->GetHeightWithScale())
        {
            m_Velocity.y *= -1;
        }
    }

    void Ball::OnRender()
    {
        Entity::OnRender();

        DrawCircleV(m_Position, m_Radius, RED);
    }

    void Ball::SetNewVelocity(const Vector2 speed)
    {
        m_Velocity = Vector2{ speed.x * m_BaseSpeedMultiplier, speed.y * m_BaseSpeedMultiplier };
    }

    void Ball::SetNewBaseSpeedMutator(float scalingFactor)
    {
        if (scalingFactor == 0) scalingFactor = 1.0f;
        float newBallSpeedScalingProgression = 1 + (scalingFactor * scalingFactor) / 3000.0f; // Scaling base speed
        if (newBallSpeedScalingProgression <= 0.f)  newBallSpeedScalingProgression = 1.0f;

        m_BaseSpeedMultiplier = m_BaseSpeedMultiplier * newBallSpeedScalingProgression;
    }
} // SmashBounce
