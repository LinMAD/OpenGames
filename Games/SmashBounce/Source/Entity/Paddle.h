#pragma once

#include "Entity/Entity.h"

#include "Ball.h"

namespace SmashBounce
{
    class Paddle final : public OpenGameCore::Entity
    {
    public:
        Paddle(const std::string& tagName, const std::string& uuid);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        void AddBall(const std::shared_ptr<Ball>& ball);

        [[nodiscard]] bool IsBallServed() const { return !m_IsInitialPlayPaddle; }
        [[nodiscard]] Rectangle GetShape() const { return m_PaddleRect; }

    private:
        bool m_IsInitialPlayPaddle = true; // Is player serving the ball?
        float m_PaddleSpeed = 900.0f;
        Vector2 m_PreviousMousePosition; // Track mouse movement for paddle control

        Rectangle m_PaddleRect{};

        std::shared_ptr<Ball> m_PlayersBall;
    };
} // SmashBounce
