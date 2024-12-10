#include "AboutMenu.h"

#include "MainMenu.h"
#include "../Game/ExampleGame.h"

namespace TemplateGame {
    AboutMenu::AboutMenu(ExampleGame& game): m_Game(game)
    {
    }

    void AboutMenu::OnUpdate(const float deltaTime)
    {
        AbstractMenu::OnUpdate(deltaTime);

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ESCAPE))
        {
            m_Game.SetActiveMenu<MainMenu>(std::make_shared<MainMenu>(m_Game));
        }
    }

    void AboutMenu::OnRender()
    {
        AbstractMenu::OnRender();

        constexpr std::array text = {
            "This is simple template game",
            "that is demonstrating Open Game Core.",
        };

        for (size_t i = 0; i < text.size(); i++)
        {
            GetRenderer()->RenderText(text[i], 150 + 2, 10 + i * 30 + 2, 30, 0xff);
        }

        GetRenderer()->RenderText(M_OPTION_CHOICE, 350 + 3, 350, 50, 0xffaf00ff);
        GetRenderer()->RenderText(M_OPTION_CHOICE, 350, 350 + 3, 50, 0xff);
    }
} // TemplateGame