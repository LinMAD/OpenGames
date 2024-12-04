#pragma once
#include "Scene/Scene.h"

namespace SmashBounce
{
    class ArenaScene final : public OpenGameCore::Scene
    {
    public:
        void OnUpdate(float deltaTime) override;
        void OnRender() override;

    private:
    };
} // SmashBounce
