#include "ExampleGame.h"

#include "Engine.h"
#include "../Menu/MainMenu.h"

namespace TemplateGame
{
    ExampleGame::ExampleGame()
    {
        SetActiveMenu<MainMenu>(std::make_shared<MainMenu>(*this));

        // TODO (LinMAD): Move scene to engine
        m_Scene = OpenGameCore::Scene();
        m_Scene.ToggleIsPaused();
    }

    void ExampleGame::OnUpdate(const float deltaTime)
    {
        AbstractGameInstance::OnUpdate(deltaTime);
        if (m_ActiveMenu) return;

        if (IsKeyPressed(KEY_ESCAPE))
        {
            SetActiveMenu<MainMenu>(std::make_shared<MainMenu>(*this));
            return;
        }

        if (!m_Scene.IsPaused())
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                // Create more floppy disks :D
                for (int i = 0; i < 100; i++)
                {
                    m_FloppyCount++;
                    m_Scene.CreateEntity<Floppy>(std::format("floppy-{}", i));
                }
            }

            // TODO (LinMAD): Move scene to engine
            m_Scene.OnUpdate(deltaTime);
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
            "Actors: %i", m_FloppyCount),
            500,
            20,
            30,
            0xff00ffd3
        );

        if (!m_Scene.IsPaused())
        {
            m_Scene.OnRender();
        }
    }
} // namespace TemplateGame
