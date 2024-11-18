#pragma once

#include "Game/GameInstance.h"

namespace TemplateGame
{
    /**
    * @class SampleGame
    * @brief Just a template sample game that shows how it interacts with OpenGamesEngine.
    */
    class SampleGame final : public OpenGameCore::GameInstance
    {
    public:
        void OnUpdate(float deltaTime) override;
        void OnRender() override;
    };
}
