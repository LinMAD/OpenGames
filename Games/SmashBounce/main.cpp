#include <memory>

#include "Engine.h"

#include "Source/Game/SmashBounceGame.h"

int main(void)
{
    const OpenGameCore::EngineConfig cfg{
        .Width = 300,
        .Height = (300 * 10) / 16, // Ensure 16:10 aspect ratio
        .Title = "Smash Bounce",
        .DisplayFPS = false,
        .HideCursor = true
    };

    OpenGameCore::Engine coreEngine(cfg);
    coreEngine.Run(std::make_shared<SmashBounce::SmashBounceGame>());

    return 0;
}
