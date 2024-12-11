#pragma once

#include "Game/AbstractGameInstance.h"

#include "../Entity/Score.h"
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

        void Restart();
    public:
        const std::string TAG_PLAYER = "Player";
        const std::string TAG_PLAYER_BALL = "PlayerBall";
        const std::string TAG_SCORE = "PlayerScore";

    private:
        ArenaScene* m_SceneArena{};
        std::shared_ptr<Score> m_Score;
    };
} // Template
