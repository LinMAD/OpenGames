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
        [[nodiscard]] bool IsAlive() const { return m_IsAlive; }

        [[nodiscard]] Rectangle GetShape() const { return m_Rectangle; }

    private:
        const float M_BRICK_WIDTH = 75.0f;
        const float M_BRICK_HEIGHT = 20.0f;
        bool m_IsAlive = true;

        Rectangle m_Rectangle;
    };
} // SmashBounce
