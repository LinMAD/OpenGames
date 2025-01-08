#pragma once
#include "UI/AbstractMenu.h"

namespace TemplateGame
{
    class ExampleGame;

    class AboutMenu final : public OpenGameCore::AbstractMenu
    {
    public:
        explicit AboutMenu(ExampleGame& game);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
    private:
        ExampleGame& m_Game;

        const char* M_OPTION_CHOICE = "- Back -";
    };
} // TemplateGame
