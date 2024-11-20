#include "ExampleGame.h"

#include <iostream>
#include <ostream>

#include "Engine.h"

namespace TemplateGame
{
    ExampleGame::ExampleGame()
    {
    }

    void ExampleGame::OnUpdate(const float deltaTime)
    {
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
        OpenGameCore::Engine::GetRendingHandler().RenderText(
            "This is Template Game Example",
            5,
            20,
            30,
            0xff0000d3
        );
        OpenGameCore::Engine::GetRendingHandler().RenderText(
            TextFormat("Actors: %i", m_ActorsFloppy.size()), 500, 20, 30, 0xff00ffd3
        );

        for (auto& act: m_ActorsFloppy) {
            act.OnRender();
        }
    }
} // namespace TemplateGame
