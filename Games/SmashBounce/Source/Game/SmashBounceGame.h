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
    public:
        const std::string m_TagPlayer = "Player";
        const std::string m_TagPlayerBall = "PlayerBall";

    private:

        ArenaScene* m_SceneArena{};
    };
} // Template
