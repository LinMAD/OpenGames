#pragma once

#include "Game/AbstractGameInstance.h"

#include "../Scene/ArenaScene.h"

namespace SmashBounce
{
    class SmashBounceGame final : public OpenGameCore::AbstractGameInstance
    {
    public:
        SmashBounceGame();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

    private:
        const std::string m_TagPlayer = "Player";

        ArenaScene m_SceneArena;
    };
} // Template
