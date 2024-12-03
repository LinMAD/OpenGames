#pragma once
#include <array>

#include "UI/AbstractMenu.h"

#include "../Game/ExampleGame.h"

namespace TemplateGame
{
    class MainMenu final : public OpenGameCore::AbstractMenu
    {
    public:
        explicit MainMenu(ExampleGame& game);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
    private:
        ExampleGame& m_Game;

        std::array<const char*, 2> m_OptionChoices = { "Play", "About" };
        int m_OptionSelected = 0;
    };
} // TemplateGame
