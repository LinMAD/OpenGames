#include "GameOverMenu.h"

namespace SmashBounce
{
    GameOverMenu::GameOverMenu(SmashBounceGame& game): m_Game(game)
    {
        const auto rend = GetRenderer();

        m_TitleTextHeight = 60;
        m_TitleTextWidth = MeasureText(M_TITLE_TEXT, m_TitleTextHeight);
        m_TitleTextPosition = Vector2{
            (rend->GetWidthWithScale() - static_cast<float>(m_TitleTextWidth)) / 2.0f,
            (rend->GetHeightWithScale() - static_cast<float>(m_TitleTextHeight)) / 2.0f
        };
    }

    void GameOverMenu::OnUpdate(const float deltaTime)
    {
        AbstractMenu::OnUpdate(deltaTime);

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
        {
            m_Game.Restart();
        }
    }

    void GameOverMenu::OnRender()
    {
        AbstractMenu::OnRender();

        // TODO (LinMAD): Check why text looks blurry
        const auto rend = GetRenderer();
        rend->RenderTextWithFont(
            M_TITLE_TEXT,
            static_cast<int>(m_TitleTextPosition.x) + 30,
            static_cast<int>(m_TitleTextPosition.y)  - m_TitleTextHeight,
            m_TitleTextHeight,
            0x722F37ff
        );
        rend->RenderTextWithFont(
            M_OPTION_CHOICE,
            static_cast<int>(rend->GetWidthWithScale() / 2) - 25 * rend->GetScale(),
            static_cast<int>(rend->GetHeightWithScale() / 2) + m_TitleTextHeight,
            30,
            0x000000ff
        );
    }
} // SmashBounceGame
