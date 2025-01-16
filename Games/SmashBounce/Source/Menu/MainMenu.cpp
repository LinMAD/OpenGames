#include "MainMenu.h"

#include "../Constants/ColorPicker.h"
#include "../Game/SmashBounceGame.h"

namespace SmashBounce
{
    MainMenu::MainMenu(SmashBounceGame& game): m_Game(game)
    {
    }

    void MainMenu::OnUpdate(const float deltaTime)
    {
        AbstractMenu::OnUpdate(deltaTime);

        // TODO (LinMAD): Add mouse support to select menu options

        if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && m_OptionSelected < m_OptionChoices.size())
        {
            m_OptionSelected++;
        }
        if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && m_OptionSelected > 0)
        {
            m_OptionSelected--;
        }

        if (m_OptionSelected < 0) m_OptionSelected = 0;
        if (m_OptionSelected > 1) m_OptionSelected = 1;

        // About
        if (m_OptionSelected == 1 && IsKeyPressed(KEY_ENTER))
        {
            // TODO (LinMAD): Add later about menu
            //m_Game.SetActiveMenu<AboutMenu>(std::make_shared<AboutMenu>(m_Game));
        }

        // Play
        if (m_OptionSelected == 0 && (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)))
        {
            m_Game.Restart();
        }
    }

    void MainMenu::OnRender()
    {
        AbstractMenu::OnRender();

        GetRenderer()->RenderTextWithFont(
            "Smash Bounce",
            static_cast<int>(GetRenderer()->GetWidthWithScale() / 2) - 110 * GetRenderer()->GetScale(),
            100,
            100,
            COLOR_PICKER_DARK_BLUE
        );

        for (size_t i = 0; i < m_OptionChoices.size(); i++)
        {
            unsigned int optionColor = COLOR_PICKER_LIGHT_GRAY;
            const char* option = m_OptionChoices[i];
            if (i == m_OptionSelected) optionColor = COLOR_PICKER_LIGHT_BLUE;

            if (i == 0)
            {
                GetRenderer()->RenderTextWithFont(
                    option,
                    static_cast<int>(GetRenderer()->GetWidthWithScale() / 2) - 20 * GetRenderer()->GetScale(),
                    static_cast<int>(GetRenderer()->GetHeightWithScale() / 2 + static_cast<float>(i) * 0),
                    50,
                    COLOR_PICKER_BLACK
                );
                GetRenderer()->RenderTextWithFont(
                    option,
                    static_cast<int>(GetRenderer()->GetWidthWithScale() / 2) - 20 * GetRenderer()->GetScale(),
                    static_cast<int>(GetRenderer()->GetHeightWithScale() / 2 + static_cast<float>(i) * 60 + 3),
                    50,
                    optionColor
                );
            }
            else
            {
                GetRenderer()->RenderTextWithFont(
                    option,
                    static_cast<int>(GetRenderer()->GetWidthWithScale() / 2) - 25 * GetRenderer()->GetScale(),
                    static_cast<int>(GetRenderer()->GetHeightWithScale() / 2 + static_cast<float>(i) * 60),
                    50,
                    COLOR_PICKER_BLACK
                );
                GetRenderer()->RenderTextWithFont(
                    option,
                    static_cast<int>(GetRenderer()->GetWidthWithScale() / 2) - 25 * GetRenderer()->GetScale(),
                    static_cast<int>(GetRenderer()->GetHeightWithScale() / 2 + static_cast<float>(i) * 60 + 3),
                    50,
                    optionColor
                );
            }
        }
    }
} // SmashBounce
