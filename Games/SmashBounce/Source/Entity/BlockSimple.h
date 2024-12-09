#pragma once

#include "Entity/Entity.h"

namespace SmashBounce
{
    class BlockSimple : public OpenGameCore::Entity
    {
    public:
        BlockSimple(const std::string& tagName, const std::string& uuid);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        void SetLeftCornerLocation(Vector2 topLeftCorner);

        void SetAlive(const bool alive) { m_IsAlive = alive; }
        bool IsAlive() const { return m_IsAlive; }

        [[nodiscard]] Rectangle GetShape() const { return m_Rectangle; }

    private:
        const float m_BrickWidth = 75.0f;
        const float m_BrickHeight = 20.0f;
        bool m_IsAlive = true;

        Rectangle m_Rectangle;
    };
} // SmashBounce
