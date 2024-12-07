#pragma once

#include "Game/AbstractGameInstance.h"

#include "../Entity/Ball.h"
#include "../Entity/BlockSimple.h"
#include "../Scene/ArenaScene.h"

namespace SmashBounce
{
    class Paddle;

    class SmashBounceGame final : public OpenGameCore::AbstractGameInstance
    {
    public:
        SmashBounceGame();
        ~SmashBounceGame() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

    private:
        bool m_IsGameOver = false;
        const int m_BrickRows = 5;
        const int m_BrickColumns = 11;

        const std::string m_TagPlayer = "Player";
        const std::string m_TagBall = "Ball";

        ArenaScene m_SceneArena;

        std::shared_ptr<Paddle> m_Player;
        std::shared_ptr<Ball> m_PlayersBall;
        std::vector<std::shared_ptr<BlockSimple>> m_BricksCollection;
    };
} // Template
