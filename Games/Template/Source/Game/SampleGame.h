#pragma once

#include "Game/GameInstance.h"

namespace TemplateGame
{
    class SampleGame : public OpenGameCore::GameInstance
    {
    public:
        void OnUpdate(float deltaTime);
        void OnRender();
    };
}
