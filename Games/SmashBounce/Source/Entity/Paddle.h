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

    private:
        void Init();

    private:
        float m_PaddleSpeed = 500.0f;
        Rectangle m_PaddleRect{};
    };
} // SmashBounce
