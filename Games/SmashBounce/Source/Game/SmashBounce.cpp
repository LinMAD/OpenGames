#include "SmashBounce.h"

namespace SmashBounce
{
    SmashBounceGame::SmashBounceGame()
    {
        m_TextHeight = 30;
        m_TextWidth = MeasureText(m_Text, m_TextHeight);

        const auto rend = GetRenderer();
        m_TextPosition = Vector2{
            static_cast<float>(rend->GetWidth() * rend->GetScale() - m_TextWidth) / 3.0f,
            static_cast<float>(rend->GetHeight() * rend->GetScale() - m_TextHeight) / 2.0f
        };
    }

    void SmashBounceGame::OnUpdate(const float deltaTime)
    {
        AbstractGameInstance::OnUpdate(deltaTime);
    }

    void SmashBounceGame::OnRender()
    {
        AbstractGameInstance::OnRender();

        GetRenderer()->RenderText(
            m_Text,
            static_cast<int>(m_TextPosition.x),
            static_cast<int>(m_TextPosition.y),
            m_TextHeight,
            0x0000ffd3
        );
    }
} // Template
