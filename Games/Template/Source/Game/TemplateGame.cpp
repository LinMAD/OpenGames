#include "TemplateGame.h"

namespace Template
{
    TemplateGame::TemplateGame()
    {
        m_TitleTextHeight = 30;
        m_TitleTextWidth = MeasureText(M_TITLE_TEXT, m_TitleTextHeight);

        const auto rend = GetRenderer();
        m_TitleTextPosition = Vector2{
            rend->GetWidthWithScale()  / 1.5f - static_cast<float>(m_TitleTextWidth),
            rend->GetHeightWithScale() / 2.0f - static_cast<float>(m_TitleTextHeight)
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
