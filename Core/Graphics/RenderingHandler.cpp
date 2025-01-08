#include "RenderingHandler.h"

namespace OpenGameCore
{
    RenderingHandler::RenderingHandler(const int width, const int height, const int scale)
        : m_Width(width), m_Height(height), m_Scale(scale)
    {
        m_TextureManager = std::make_shared<TextureManager>();
    }

    RenderingHandler::~RenderingHandler()
    {
        UnloadFont(m_CustomFont);
    }

    void RenderingHandler::AddFont(const std::string& filePath)
    {
        // TODO (LinMAD): If custom found not found, can be used default?
        if (const std::filesystem::path fontPath{filePath}; !std::filesystem::exists(fontPath)) {
            throw std::runtime_error("Font file not found: " + fontPath.string());
        }

        m_CustomFont = LoadFontEx(filePath.c_str(), 32, nullptr, 250);
        SetTextureFilter(m_CustomFont.texture, TEXTURE_FILTER_POINT);
    }

    void RenderingHandler::RenderText(
        const char* text,
        const int posX,
        const int posY,
        const unsigned int fontSize,
        const unsigned int colorHexValue
    )
    {
        DrawText(text, posX, posY, static_cast<int>(fontSize), GetColor(colorHexValue));
    }

    void RenderingHandler::RenderTextWithFont(
        const char* text,
        const int posX,
        const int posY,
        const unsigned int fontSize,
        const unsigned int colorHexValue
    )
    {
        DrawTextEx(m_CustomFont, text, Vector2(static_cast<float>(posX), static_cast<float>(posY)), static_cast<float>(fontSize), 0.0f, GetColor(colorHexValue));
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
