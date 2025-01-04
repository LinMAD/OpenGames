#pragma once

#include "Entity/Entity.h"

namespace SmashBounce
{
    class Ball : public OpenGameCore::Entity
    {
    public:
        Ball(const std::string& tagName, const std::string& uuid);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        void SetNewVelocity(Vector2 speed);
        void SetNewBaseSpeedMutator(float scalingFactor);
        void SetNewPosition(const Vector2 position) { m_Position = position; }

        [[nodiscard]] Vector2 GetVelocity() const { return m_Velocity; }
        [[nodiscard]] Vector2 GetPosition() const { return m_Position; }
        [[nodiscard]] float GetRadius() const { return m_Radius; }

    private:
        Vector2 m_Position{};
        Vector2 m_Velocity{};
        float m_Radius;
        float m_BaseSpeedMultiplier = 1.0f;
    };
} // SmashBounce
