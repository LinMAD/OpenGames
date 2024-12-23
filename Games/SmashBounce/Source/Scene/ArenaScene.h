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
         */
        void NewLevelProgression();

    protected:
        /**
         * @return float
         */
        [[nodiscard]] float GetPlayerLevelPlayTime() const;

    private:
        void CollisionCheck();

    private:
        const int M_BRICK_ROWS = 5;
        const int M_BRICK_COLUMNS = 11;
        const std::string M_LEVEL_UP_TEXT = "Level Up";

        bool m_IsGameOver = false;
        bool m_LevelCleared = false;

        std::chrono::time_point<std::chrono::steady_clock> m_levelUpStartTime;
        int m_LevelUpDelay = 1000; // Delay duration in milliseconds

        // When scene started and how long player is playing
        using Clock = std::chrono::high_resolution_clock;
        std::chrono::time_point<Clock> m_TimeStarted;
        std::string m_TimeElapsedText;
        int  m_TimeElapsedTextHeight = 25;
        int  m_TimeElapsedTextWidth = 0;
        Vector2  m_TimeElapsedTextPosition{};

        SmashBounceGame& m_Game;

        std::shared_ptr<Paddle> m_PlayersPaddle;
        std::shared_ptr<Ball> m_PlayersBall;
        std::vector<std::shared_ptr<BlockSimple>> m_BricksCollection;
        std::shared_ptr<Score> m_Score;
    };
} // SmashBounce
