#ifndef PLAINTETRIS_TETROMINOCOMPONENT_H
#define PLAINTETRIS_TETROMINOCOMPONENT_H

namespace component {
    // All types of figures
    enum TetrominoType {
        C, I, L, N, T,
    };

    // All figures sprites
    static const char *TetrominoSprite[][4] = {
            {
                    " *  "
                    " *  "
                    " *  "
                    " *  ",
                    "    "
                    "****"
                    "    "
                    "    ",
                    " *  "
                    " *  "
                    " *  "
                    " *  ",
                    "    "
                    "****"
                    "    "
                    "    ",
            },
            {
                    "  * "
                    "  * "
                    " ** "
                    "    ",
                    "    "
                    "*   "
                    "*** "
                    "    ",
                    " ** "
                    " *  "
                    " *  "
                    "    ",
                    "    "
                    "    "
                    "*** "
                    "  * ",
            },
            {
                    " *  "
                    " *  "
                    " ** "
                    "    ",
                    "    "
                    "*** "
                    "*   "
                    "    ",
                    " ** "
                    "  * "
                    "  * "
                    "    ",
                    "  * "
                    "*** "
                    "    "
                    "    ",
            },
            {
                    "    "
                    " ** "
                    " ** "
                    "    ",
                    "    "
                    " ** "
                    " ** "
                    "    ",
                    "    "
                    " ** "
                    " ** "
                    "    ",
                    "    "
                    " ** "
                    " ** "
                    "    ",
            },
            {
                    "  * "
                    " ** "
                    " *  "
                    "    ",
                    "    "
                    "**  "
                    " ** "
                    "    ",
                    "  * "
                    " ** "
                    " *  "
                    "    ",
                    "    "
                    "**  "
                    " ** "
                    "    ",
            },
            {
                    " *  "
                    " ** "
                    " *  "
                    "    ",
                    "    "
                    "*** "
                    " *  "
                    "    ",
                    " *  "
                    "**  "
                    " *  "
                    "    ",
                    " *  "
                    "*** "
                    "    "
                    "    ",
            },
            {
                    " *  "
                    " ** "
                    "  * "
                    "    ",
                    "    "
                    " ** "
                    "**  "
                    "    ",
                    " *  "
                    " ** "
                    "  * "
                    "    ",
                    "    "
                    " ** "
                    "**  "
                    "    ",
            },
    };
}

#endif //PLAINTETRIS_TETROMINOCOMPONENT_H
