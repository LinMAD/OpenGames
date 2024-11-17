#include <memory>

#include "Application.h"

#include "Source/Game/SampleGame.h"

int main(void)
{
    const OpenGameCore::ApplicationConfig cfg{
        .Width = 300,
        .Title = "Template"
    };

    OpenGameCore::Application app(cfg);
    app.Run(std::unique_ptr<TemplateGame::SampleGame>());

    return 0;
}
