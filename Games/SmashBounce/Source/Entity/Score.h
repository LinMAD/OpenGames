#pragma once
#include "Entity/Entity.h"

namespace SmashBounce
{
    class Score final : public OpenGameCore::Entity
    {
    public:
        Score(const std::string& tagName, const std::string& uuid);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        void Reset();

        void AddPoints(unsigned int score);
        void CalculateLevelBonus(int baseBonus = 500);

        // TODO (LinMAD): Add time based score (LVL UP)

    private:
        unsigned int m_Score{};       // total score
        std::string m_ScoreText;
        int m_ScoreTextHeight = 35;
        int m_ScoreTextWidth = 0;
        Vector2 m_ScoreTextPosition{};

        unsigned int m_CurrentLevel{}; // multiplier
        std::string m_LevelText;
        int m_LevelTextHeight = 25;
        int m_LevelTextWidth = 0;
        Vector2 m_LevelTextPosition{};
    };
} // SmashBounce
