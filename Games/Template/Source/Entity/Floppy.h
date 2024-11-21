#pragma once
#include "Entity/AbstractEntity.h"
#include "Graphics/TextureManager.h"

namespace TemplateGame
{
    class Floppy final : public OpenGameCore::AbstractEntity
    {
    public:
        explicit Floppy();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

    private:
        const std::string m_TextureId = "Floppy";
        const Texture2D* m_TextureFloppy;

        Vector2 m_Position{};
        Vector2 m_Speed{};
        unsigned int m_Color;
    };
} // TemplateGame
