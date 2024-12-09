#pragma once

#include "Scene/Scene.h"

#include "../Entity/Ball.h"
#include "../Entity/Paddle.h"
#include "../Entity/BlockSimple.h"

namespace SmashBounce
{
    class SmashBounceGame;

    class ArenaScene final : public OpenGameCore::Scene
    {
    public:
        explicit ArenaScene(SmashBounceGame& game);
        ~ArenaScene() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        [[nodiscard]] bool IsGameOver() const { return m_IsGameOver; }

        bool SetIsGameOver(const bool isGameOver)
        {
            m_IsGameOver = isGameOver;
            return m_IsGameOver;
        }

    private:
        bool m_IsGameOver = false;
        const int m_BrickRows = 5;
        const int m_BrickColumns = 11;

        SmashBounceGame& m_Game;

        std::shared_ptr<Paddle> m_PlayersPaddle;
        std::shared_ptr<Ball> m_PlayersBall;

        std::vector<std::shared_ptr<BlockSimple>> m_BricksCollection;
    };
} // SmashBounce
