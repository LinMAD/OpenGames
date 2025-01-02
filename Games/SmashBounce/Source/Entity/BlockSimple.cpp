#include "BlockSimple.h"

namespace SmashBounce
{
    BlockSimple::BlockSimple(const std::string& tagName, const std::string& uuid): Entity(tagName, uuid), m_Rectangle()
    {
    }

    void BlockSimple::OnUpdate(const float deltaTime)
    {
        Entity::OnUpdate(deltaTime);
    }

    void BlockSimple::OnRender()
    {
        Entity::OnRender();

        if (m_IsAlive) DrawRectangleRec(m_Rectangle, BLUE);
    }

    unsigned int BlockSimple::GetScorePoints()
    {
        return 10;
    }

    Vector2 BlockSimple::GetPosition() const
    {
        return Vector2(m_Rectangle.x + m_Rectangle.width / 2, m_Rectangle.y);
    }

    void BlockSimple::SetLeftCornerLocation(const Vector2 topLeftCorner)
    {
        m_Rectangle = Rectangle({
            topLeftCorner.x * (M_BRICK_WIDTH + 5) + 10,
            topLeftCorner.y *(M_BRICK_HEIGHT + 5) + 50,
            M_BRICK_WIDTH,
            M_BRICK_HEIGHT
        });
    }
} // SmashBounce
