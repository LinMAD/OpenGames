#pragma once

#include "Game/AbstractGameInstance.h"

#include "../Scene/ArenaScene.h"

namespace SmashBounce
{
    class SmashBounceGame final : public OpenGameCore::AbstractGameInstance
    {
    public:
        SmashBounceGame();
        ~SmashBounceGame() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        void Restart();
    private:
        ArenaScene* m_SceneArena{};
    };
} // Template
