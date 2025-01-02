#pragma once
#include <random>

namespace OpenGameCore {
    /**
     * @class UuidGenerator
     * @brief Unique ID generator.
     */
    class UuidGenerator {
    public:
        UuidGenerator();

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
