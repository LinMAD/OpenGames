#pragma once

#include "TextureManager.h"

namespace OpenGameCore
{
    /**
     * @class RenderingHandler
     * @brief Represents graphic rendering handling.
     */
    class RenderingHandler
    {
    public:
        RenderingHandler(int width, int height, int scale);
        ~RenderingHandler() = default;

        /**
         * Rendering simple text on the screen.
         *
         * @param text
         * @param posX
         * @param posY
         * @param fontSize
         * @param colorHexValue
         */
        void RenderText(const char* text, int posX, int posY, unsigned int fontSize, unsigned int colorHexValue);

        /**
         * Render simple sprite.
         *
         * @param texture
         * @param position
         * @param colorHexValue
         */
        void RenderSprite(const Texture2D& texture, Vector2 position, unsigned int colorHexValue);

        [[nodiscard]] float GetWidth() const { return static_cast<float>(m_Width * m_Scale); }
        [[nodiscard]] float GetHeight() const { return  static_cast<float>(m_Height * m_Scale); }
        [[nodiscard]] int GetScale() const { return m_Scale; }

    public:
        /**
         * @return TextureManager
         */
        std::shared_ptr<TextureManager> GetTextureManager();

    private:
        int m_Width = 100;
        int m_Height = 100;
        int m_Scale = 1;

        std::shared_ptr<TextureManager> m_TextureManager;
    };
} // OpenGameCore
