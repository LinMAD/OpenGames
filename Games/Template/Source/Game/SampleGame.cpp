#include "SampleGame.h"

#include <iostream>
#include <ostream>

#include "Engine.h"

namespace TemplateGame
{
    void SampleGame::OnUpdate(const float deltaTime)
    {
        std::cout << "Updating game with deltaTime: " << deltaTime << std::endl;
    }

    void SampleGame::OnRender()
    {
        OpenGameCore::Engine::GetRendingHandler().RenderText(
            "Congrats! You created your first window!",
            130,
            200,
            30,
            0xff0000d3
        );
    }
} // namespace TemplateGame
