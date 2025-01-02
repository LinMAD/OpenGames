#pragma once
#include <random>

namespace OpenGameCore
{
    /**
     * @class BooleanGenerator
     * @brief Boolean value generator.
     */
    class BooleanGenerator
    {
    public:
        BooleanGenerator();

        bool GetRandomBool();

    private:
        std::mt19937 m_Engine;
    };
} // OpenGameCore
