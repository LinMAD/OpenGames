#pragma once

namespace OpenGameCore
{
    /**
     * @class GameInstance
     * @brief An Interface of concrete game logic that will be interacting with Application.
     */
    class GameInstance
    {
    public:
        virtual ~GameInstance() = default;

        virtual void OnUpdate(float deltaTime) = 0;
        virtual void OnRender() = 0;
    };
} // OpenGameCore
