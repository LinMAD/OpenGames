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
        Vector2 GetSpeed() const { return m_Speed; }

        Vector2 GetPosition() const { return m_Position; }

        float GetRadius() const { return m_Radius; }

    private:
        Vector2 m_Position{};
        Vector2 m_Speed{};
        float m_Radius;
    };
} // SmashBounce
