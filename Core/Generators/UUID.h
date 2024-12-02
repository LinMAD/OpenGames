#pragma once
#include <random>

namespace OpenGameCore {
    /**
     * @class UUID
     * @brief Unique ID generator.
     */
    class UUID {
    public:
        UUID();

        /**
         * @brief Regenerate new UUID.
         * @return string
         */
        std::string Generate();

    private:
        std::mt19937 m_Generator;
        std::uniform_int_distribution<uint64_t> m_UniformDistribution;
    };
} // OpenGamesCore
