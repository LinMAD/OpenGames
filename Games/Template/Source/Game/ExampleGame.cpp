#include "ExampleGame.h"

#include "Engine.h"
#include "../Menu/MainMenu.h"

namespace TemplateGame
{
    ExampleGame::ExampleGame()
    {
        SetActiveMenu<MainMenu>(std::make_shared<MainMenu>(*this));
    }

    void ExampleGame::OnUpdate(const float deltaTime)
    {
        AbstractGameInstance::OnUpdate(deltaTime);
        if (m_ActiveMenu) return;

        // TODO Think how to separate UI form Game logic update
        if (IsKeyPressed(KEY_ESCAPE))
        {
            SetActiveMenu<MainMenu>(std::make_shared<MainMenu>(*this));
            return;
        }

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            // Create more floppy disks :D
            for (int i = 0; i < 100; i++)
            {
                m_ActorsFloppy.emplace_back(Floppy());
            }
        }

        for (auto& act: m_ActorsFloppy) {
            act.OnUpdate(deltaTime);
        }
    }

    void ExampleGame::OnRender()
    {
        AbstractGameInstance::OnRender();

        if (m_ActiveMenu) return;

        GetRenderer()->RenderText(
            "This is Template Game Example",
            5,
            20,
            30,
            0xff0000d3
        );
        GetRenderer()->RenderText(TextFormat(
            "Actors: %i", m_ActorsFloppy.size()),
            500,
            20,
            30,
            0xff00ffd3
        );

        for (auto& act: m_ActorsFloppy) {
            act.OnRender();
        }
    }
} // namespace TemplateGame
