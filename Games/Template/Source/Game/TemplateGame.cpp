#include "TemplateGame.h"

namespace Template
{
    TemplateGame::TemplateGame()
    {
        m_TitleTextHeight = 30;
        m_TitleTextWidth = MeasureText(M_TITLE_TEXT, m_TitleTextHeight);

        const auto rend = GetRenderer();
        m_TitleTextPosition = Vector2{
            rend->GetWidthWithScale() - static_cast<float>(m_TitleTextWidth) / 3.0f,
            rend->GetHeightWithScale() - static_cast<float>(m_TitleTextHeight) / 2.0f
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
            M_TITLE_TEXT,
            static_cast<int>(m_TitleTextPosition.x),
            static_cast<int>(m_TitleTextPosition.y),
            m_TitleTextHeight,
            0x0000ffd3
        );
    }
} // Template
