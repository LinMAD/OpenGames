#pragma once

#include "Scene/Scene.h"

#include "../Entity/Ball.h"
#include "../Entity/Paddle.h"
#include "../Entity/BlockSimple.h"

namespace SmashBounce
{
    class Score;
    class SmashBounceGame;

    class ArenaScene final : public OpenGameCore::Scene
    {
    public:
        explicit ArenaScene(SmashBounceGame& game);
        ~ArenaScene() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        [[nodiscard]] bool IsGameOver() const { return m_IsGameOver; }
        [[nodiscard]] bool IsLevelCleared() const { return m_LevelCleared; }

        bool SetIsGameOver(const bool isGameOver)
        {
            m_IsGameOver = isGameOver;
            return m_IsGameOver;
        }

        /**
         * Generate new level based on given difficulty
         * TODO (LinMAD): Add level difficulty mutator
         */
        void NewLevelProgression();

    private:
        void CollisionCheck();

    private:
        const int M_BRICK_ROWS = 5;
        const int M_BRICK_COLUMNS = 11;
        const std::string M_LEVEL_UP_TEXT = "Level Up";

        bool m_IsGameOver = false;
        bool m_LevelCleared = false;

        std::chrono::time_point<std::chrono::steady_clock> m_levelUpStartTime;
        int m_levelUpDelay = 1000; // Delay duration in milliseconds (e.g., 2 seconds)

        SmashBounceGame& m_Game;

        std::shared_ptr<Paddle> m_PlayersPaddle;
        std::shared_ptr<Ball> m_PlayersBall;
        std::vector<std::shared_ptr<BlockSimple>> m_BricksCollection;
        std::shared_ptr<Score> m_Score;
    };
} // SmashBounce
