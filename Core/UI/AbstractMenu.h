#pragma once
#include "EngineComponent.h"

namespace OpenGameCore
{
    /**
    * @class AbstractMenu
    * @brief Abstract class for UI related screens.
    */
    class AbstractMenu : public EngineComponent
    {
    public:
        ~AbstractMenu() override = default;
    };
} // OpenGameCore
