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

    void BlockSimple::SetLeftCornerLocation(const Vector2 topLeftCorner)
    {
        m_Rectangle = Rectangle({
            topLeftCorner.x * (m_BrickWidth + 5) + 10,
            topLeftCorner.y *(m_BrickHeight + 5) + 50,
            m_BrickWidth,
            m_BrickHeight
        });
    }
} // SmashBounce
