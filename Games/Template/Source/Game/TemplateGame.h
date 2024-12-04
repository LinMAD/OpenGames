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
        const char* m_Text = "This is Template Game";

        int m_TextHeight;
        int m_TextWidth;
        Vector2 m_TextPosition{};
    };
} // Template
