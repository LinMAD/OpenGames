#include "TemplateGame.h"

namespace Template
{
    TemplateGame::TemplateGame()
    {
        m_TextHeight = 30;
        m_TextWidth = MeasureText(m_Text, m_TextHeight);

        const auto rend = GetRenderer();
        m_TextPosition = Vector2{
            rend->GetWidth() - m_TextWidth / 3.0f,
            rend->GetHeight() - m_TextHeight / 2.0f
        };
    }

    void TemplateGame::OnUpdate(const float deltaTime)
    {
        AbstractGameInstance::OnUpdate(deltaTime);
    }

    void TemplateGame::OnRender()
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
