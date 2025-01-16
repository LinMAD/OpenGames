#pragma once

#include <array>

#include "UI/AbstractMenu.h"

#include "../Game/SmashBounceGame.h"

namespace SmashBounce
{
    class MainMenu final : public OpenGameCore::AbstractMenu
    {
    public:
        explicit MainMenu(SmashBounceGame& game);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
    private:
        SmashBounceGame& m_Game;

        std::array<const char*, 2> m_OptionChoices = { "Play", "About" };
        int m_OptionSelected = 0;
    };
} // SmashBounce
