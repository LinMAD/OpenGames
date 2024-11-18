#include "RenderingHandler.h"

namespace OpenGameCore
{
    RenderingHandler::RenderingHandler(const int width, const int height) : m_Width(width), m_Height(height)
    {
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
} // OpenGameCore
