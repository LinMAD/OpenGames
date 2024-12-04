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

        [[nodiscard]] int GetWidth() const { return m_Width; }
        [[nodiscard]] int GetHeight() const { return m_Height; }
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
