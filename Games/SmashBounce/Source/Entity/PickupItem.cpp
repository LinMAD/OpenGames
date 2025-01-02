#include "PickupItem.h"

namespace SmashBounce
{
    PickupItem::PickupItem(const std::string& tagName, const std::string& uuid): Entity(tagName, uuid)
    {
    }

    void PickupItem::OnUpdate(const float deltaTime)
    {
        Entity::OnUpdate(deltaTime);

        if (!m_Active) return;

        m_Position.y += m_FallingSpeed;
    }

    void PickupItem::OnRender()
    {
        Entity::OnRender();
    }
} // SmashBounce
