#include "Score.h"

#include "../Constants/ColorPicker.h"

namespace SmashBounce
{
    Score::Score(const std::string& tagName, const std::string& uuid): Entity(tagName, uuid)
    {
        Reset();
    }

    void Score::OnUpdate(const float deltaTime)
    {
        Entity::OnUpdate(deltaTime);

        const auto rend = GetRenderer();

        m_ScoreText = "Score: " + std::to_string(m_Score);
        m_ScoreTextWidth = MeasureText(m_ScoreText.c_str(), m_ScoreTextHeight);
        m_ScoreTextPosition = Vector2{10};

        m_LevelText = "Level: " + std::to_string(m_CurrentLevel);
        m_LevelTextWidth = MeasureText(m_LevelText.c_str(), m_LevelTextHeight);
        m_LevelTextPosition = Vector2{10, 25};
    }

    void Score::OnRender()
    {
        Entity::OnRender();

        GetRenderer()->RenderTextWithFont(
            m_ScoreText.c_str(),
            static_cast<int>(m_ScoreTextPosition.x),
            static_cast<int>(m_ScoreTextPosition.y),
            m_ScoreTextHeight,
            COLOR_PICKER_LIGHT_BLUE
        );
        GetRenderer()->RenderTextWithFont(
            m_LevelText.c_str(),
            static_cast<int>(m_LevelTextPosition.x),
            static_cast<int>(m_LevelTextPosition.y),
            m_LevelTextHeight,
            COLOR_PICKER_DARK_BLUE
        );
    }

    void Score::Reset()
    {
        m_Score = 0;
        m_CurrentLevel = 1;
    }

    void Score::AddPoints(const unsigned int score)
    {
        m_Score += score * m_CurrentLevel; // Base points multiplied by the combo
    }

    void Score::CalculateLevelBonus(const int baseBonus)
    {
        m_Score += baseBonus;
        m_CurrentLevel++;
    }
} // SmashBounce
