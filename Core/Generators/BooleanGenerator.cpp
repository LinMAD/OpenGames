#include "BooleanGenerator.h"

namespace OpenGameCore
{
    BooleanGenerator::BooleanGenerator() : m_Engine(std::random_device{}())
    {
    }

    bool BooleanGenerator::GetRandomBool()
    {
        return m_Engine() & 1; // Use the least bit for boolean
    }
} // OpenGameCore
