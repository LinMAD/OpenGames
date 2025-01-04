#include "PickupItemMarbles.h"

namespace SmashBounce
{
    PickupItemMarbles::PickupItemMarbles(const std::string& tagName, const std::string& uuid): PickupItem(tagName, uuid)
    {
        m_FallingSpeed = 3.f;
    }

    void PickupItemMarbles::OnUpdate(const float deltaTime)
    {
        PickupItem::OnUpdate(deltaTime);

        // Is it fall out of screen?
        if (m_Position.y > GetRenderer()->GetHeightWithScale())
        {
           m_Active = false;
        }
    }

    void PickupItemMarbles::OnRender()
    {
        PickupItem::OnRender();

        if (!m_Active) return;

        // TODO (LinMAD): Replace this with texture
        DrawCircleV(Vector2{m_Position.x - m_Radius, m_Position.y}, m_Radius / 2, BLACK);
        DrawCircleV(Vector2{m_Position.x + m_Radius, m_Position.y}, m_Radius / 2, BLACK);
    }

    bool PickupItemMarbles::GetIsActive() const
    {
        return m_Active;
    }

    void PickupItemMarbles::SetActive(const bool active)
    {
        m_Active = active;
    }

    void PickupItemMarbles::SetNewPosition(const Vector2 position)
    {
        m_Position = position;
    }
}
