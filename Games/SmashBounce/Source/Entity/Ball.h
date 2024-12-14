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

        void SetNewSpeed(const Vector2 speed) { m_Speed = speed; }
        void SetNewPosition(const Vector2 position ){ m_Position = position; }

        [[nodiscard]] Vector2 GetSpeed() const { return m_Speed; }
        [[nodiscard]] Vector2 GetPosition() const { return m_Position; }
        [[nodiscard]] float GetRadius() const { return m_Radius; }

    private:
        Vector2 m_Position{};
        Vector2 m_Speed{};
        float m_Radius;
    };
} // SmashBounce
