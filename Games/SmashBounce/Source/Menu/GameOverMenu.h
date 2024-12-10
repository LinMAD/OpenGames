#pragma once

#include <array>

#include "UI/AbstractMenu.h"

#include "../Game/SmashBounceGame.h"

namespace SmashBounce
{
    class GameOverMenu : public OpenGameCore::AbstractMenu
    {
    public:
        explicit GameOverMenu(SmashBounceGame& game);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

    private:
        const char* M_OPTION_CHOICE = "- Retry -";

        // Game over related
        const char* M_TITLE_TEXT = "Game Over";
        int m_TitleTextHeight = 60;
        int m_TitleTextWidth = 0;
        Vector2 m_TitleTextPosition{};

        SmashBounceGame& m_Game;
    };
} // SmashBounce