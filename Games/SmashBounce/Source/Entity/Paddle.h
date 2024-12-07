#pragma once
#include "Entity/Entity.h"

namespace SmashBounce
{
    class Paddle final : public OpenGameCore::Entity
    {
    public:
        Paddle(const std::string& tagName, const std::string& uuid);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        Rectangle GetShape() const { return m_PaddleRect; }

    private:
        float m_PaddleSpeed = 900.0f;
        Rectangle m_PaddleRect{};
    };
} // SmashBounce
