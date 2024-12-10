#pragma once
#include "Game/AbstractGameInstance.h"

namespace Template
{
    class TemplateGame final : public OpenGameCore::AbstractGameInstance
    {
    public:
        TemplateGame();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

    private:
        const char* M_TITLE_TEXT = "This is Template Game";

        int m_TitleTextHeight;
        int m_TitleTextWidth;
        Vector2 m_TitleTextPosition{};
    };
} // Template
