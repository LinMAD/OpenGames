#include "MainMenu.h"

#include "AboutMenu.h"

namespace TemplateGame
{
    MainMenu::MainMenu(ExampleGame& game): m_Game(game)
    {
    }

    void MainMenu::OnUpdate(const float deltaTime)
    {
        AbstractMenu::OnUpdate(deltaTime);

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

    	if (m_OptionSelected == 1)
    	{
    		if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    		{
    			m_Game.SetActiveMenu<AboutMenu>(std::make_shared<AboutMenu>(m_Game));
    		}
    	}

        if (m_OptionSelected == 0 && (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)))
        {
            m_Game.SetActiveMenu<AbstractMenu>(nullptr);
        }
    }

    void MainMenu::OnRender()
    {
        AbstractMenu::OnRender();

        GetRenderer()->RenderText("Demo Menu", 180, 30, 100, 0xff);

        for (size_t i = 0; i < m_OptionChoices.size(); i++)
		{
			std::string selectedOption;
			const char* option = m_OptionChoices[i];
			if (i == m_OptionSelected)
			{
				selectedOption = std::format("- {} -", m_OptionChoices[i]);
				option = selectedOption.c_str();
			}

			GetRenderer()->RenderText(option, 350 + 3, 150 + i * 60, 50, 0xffaf00ff);
			GetRenderer()->RenderText(option, 350, 150 + i * 60 + 3, 50, 0xff);
		}
    }
} // TemplateGame
