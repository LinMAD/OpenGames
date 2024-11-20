#pragma once

#include "Game/AbstractGameInstance.h"

#include "../Entity/Floppy.h"

namespace TemplateGame
{
    /**
    * @class ExampleGame
    * @brief Just a template sample game that shows how it interacts with OpenGamesEngine.
    */
    class ExampleGame final : public OpenGameCore::AbstractGameInstance
    {
    public:
        ExampleGame();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
    private:
        std::list<Floppy> m_ActorsFloppy;
    };
}
