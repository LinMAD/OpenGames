#pragma once
#include "Entity/Entity.h"

namespace SmashBounce
{
    class PickupItem : public OpenGameCore::Entity
    {
    public:
        PickupItem(const std::string& tagName, const std::string& uuid);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        [[nodiscard]] Vector2 GetPosition() const { return m_Position; }
        [[nodiscard]] float GetRadius() const { return m_Radius; }
        [[nodiscard]] float IsActive() const { return m_Active; }

    protected:
        float m_FallingSpeed = 2.f;
        float m_Radius = 10.f;

        bool m_Active = true;

        Vector2 m_Position = {};
    };
} // SmashBounce
