#include "Floppy.h"

#include "Engine.h"

namespace TemplateGame
{
    Floppy::Floppy(const std::string& tagName, const std::string& uuid)
        : Entity(tagName, uuid), m_TextureFloppy(nullptr), m_Color(0)
    {
        Init();
    }

    void Floppy::Init()
    {
        GetTextureManager()->AddNewTexture(M_TEXTURE_ID, "assets/textures/og_floppy_alpha.png");

        m_TextureFloppy = &GetTextureManager()->GetTexture(M_TEXTURE_ID);
        m_Position = GetMousePosition();

        m_Speed.x = static_cast<float>(GetRandomValue(-250, 250)) / 60.0f;
        m_Speed.y = static_cast<float>(GetRandomValue(-250, 250)) / 60.0f;

        const int r = GetRandomValue(50, 240);
        const int g = GetRandomValue(50, 240);
        const int b = GetRandomValue(50, 240);
        m_Color = (0xFF << 24) | (r << 16) | (g << 8) | b;
    }

    void Floppy::OnUpdate(const float deltaTime)
    {
        EngineComponent::OnUpdate(deltaTime);

        m_Position.x += m_Speed.x;
        m_Position.y += m_Speed.y;

        const auto sWidth = GetScreenWidth();
        const auto sHeight = GetScreenHeight();
        const auto isOutBounceByWidth = m_Position.x + m_Speed.x < 5 || m_Position.x + m_Speed.x >= sWidth - 35;
        const auto isOutBounceByHeight = m_Position.y + m_Speed.y < 55 || m_Position.y + m_Speed.y >= sHeight - 35;

        if (isOutBounceByWidth) m_Speed.x *= -1; else m_Speed.x *= +1;
        if (isOutBounceByHeight) m_Speed.y *= -1; else m_Speed.y *= +1;
    }

    void Floppy::OnRender()
    {
        EngineComponent::OnRender();

        GetRenderer()->RenderSprite(*m_TextureFloppy, m_Position, m_Color);
    }

    std::string Floppy::GetTextureID() const
    {
        return M_TEXTURE_ID;
    }

    Vector2 Floppy::GetPosition() const
    {
        return m_Position;
    }
} // TemplateGame
