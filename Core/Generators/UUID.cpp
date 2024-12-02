#include "UUID.h"

#include <iomanip>
#include <sstream>

namespace OpenGameCore
{
    UUID::UUID(): m_Generator(std::random_device{}()), m_UniformDistribution(0, 15)
    {
    }

    std::string UUID::Generate()
    {
        std::ostringstream uuid;

        constexpr int hex_size = 32;
        for (int i = 0; i < hex_size; ++i) {
            if (i == 8 || i == 12 || i == 16 || i == 20) {
                uuid << '-';
            }
            uuid << std::hex << std::setw(1) << m_UniformDistribution(m_Generator);
        }

        return uuid.str();
    }
} // OpenGamesCore
