#include "RenderingHandler.h"

namespace OpenGameCore
{
    RenderingHandler::RenderingHandler(const int width, const int height, const int scale)
        : m_Width(width), m_Height(height), m_Scale(scale)
    {
        m_TextureManager = std::make_shared<TextureManager>();
    }

    void RenderingHandler::RenderText(
        const char* text,
        const int posX,
        const int posY,
        const unsigned int fontSize,
        const unsigned int colorHexValue
    )
    {
        DrawText(text, posX, posY, fontSize, GetColor(colorHexValue));
    }

    void RenderingHandler::RenderSprite(const Texture2D& texture, const Vector2 position, const unsigned int colorHexValue)
    {
        // TODO Use Abstract Entity to work with texture indirectly
        DrawTextureV(texture, position, GetColor(colorHexValue));
    }

    std::shared_ptr<TextureManager> RenderingHandler::GetTextureManager()
    {
        return m_TextureManager;
    }
} // OpenGameCore
