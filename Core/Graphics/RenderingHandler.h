#pragma once

#include "raylib.h"

namespace OpenGameCore
{
    /**
     * @class RenderingHandler
     * @brief Represents graphic rendering handling.
     */
    class RenderingHandler
    {
    public:
        RenderingHandler(int width, int height);
        ~RenderingHandler() = default;

        void RenderText(const char* text, int posX, int posY, unsigned int fontSize, unsigned int colorHexValue);

    private:
        int m_Width = 0;
        int m_Height = 0;
    };
} // OpenGameCore
