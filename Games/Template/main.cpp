#include <memory>

#include "Engine.h"

#include "Source/Game/TemplateGame.h"

int main(void)
{
    const OpenGameCore::EngineConfig cfg{
        .Width = 300,
        .Height = (300 * 10) / 16, // Ensure 16:10 aspect ratio
        .Title = "Template - Game"
    };

    OpenGameCore::Engine coreEngine(cfg);
    coreEngine.Run(std::make_shared<Template::TemplateGame>());

    return 0;
}
