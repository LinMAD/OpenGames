#pragma once
#include "Entity/Entity.h"
#include "Graphics/TextureManager.h"

namespace TemplateGame
{
    class Floppy final : public OpenGameCore::Entity
    {
    public:
        Floppy();
        Floppy(const std::string& tagName, const std::string& uuid);

        void Init();
        void OnUpdate(float deltaTime) override;
        void OnRender() override;

    private:
        const std::string m_TextureId = "Floppy";
        Texture2D* m_TextureFloppy;

        Vector2 m_Position{};
        Vector2 m_Speed{};
        unsigned int m_Color;
    };
} // TemplateGame
