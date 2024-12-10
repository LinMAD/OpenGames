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
        const int M_BRICK_ROWS = 5;
        const int M_BRICK_COLUMNS = 11;

        bool m_IsGameOver = false;

        SmashBounceGame& m_Game;

        std::shared_ptr<Paddle> m_PlayersPaddle;
        std::shared_ptr<Ball> m_PlayersBall;
        std::vector<std::shared_ptr<BlockSimple>> m_BricksCollection;
    };
} // SmashBounce
