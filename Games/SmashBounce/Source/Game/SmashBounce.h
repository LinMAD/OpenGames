#pragma once

#include "Game/AbstractGameInstance.h"

#include "../Scene/ArenaScene.h"

namespace SmashBounce
{
    class SmashBounceGame final : public OpenGameCore::AbstractGameInstance
    {
    public:
        SmashBounceGame();
        ~SmashBounceGame() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

    public:
        const std::string m_TagPlayer = "Player";
        const std::string m_TagPlayerBall = "PlayerBall";

    private:
        const char* m_Text = "Game Over";
        int m_DefaultTextHeight = 60;
        int m_TextWidth = 0;
        Vector2 m_TextPosition{};

        ArenaScene* m_SceneArena{};
    };
} // Template
