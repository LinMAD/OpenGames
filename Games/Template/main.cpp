#include <memory>
#include "Engine.h"

#include "Source/Game/ExampleGame.h"

int main(void)
{
    const OpenGameCore::EngineConfig cfg{
        .Width = 300,
        .Title = "Template - Sample Game"
    };

    OpenGameCore::Engine coreEngine(cfg);
    coreEngine.Run(std::make_shared<TemplateGame::ExampleGame>());

    return 0;
}
