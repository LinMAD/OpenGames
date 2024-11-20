#pragma once

namespace OpenGameCore
{
    /**
     * @class AbstractGameInstance
     * @brief Represents an abstract game instance, providing a foundation for
     *        concrete game implementations to define their specific logic
     *        and interactions with the application.
     */
    class AbstractGameInstance
    {
    public:
        virtual ~AbstractGameInstance() = default;

        /***
         * @brief Called inside Engine when update must be done.
         */
        virtual void OnUpdate(float deltaTime) = 0;
        /***
         * @brief Called inside Engine when screen render will be called.
         */
        virtual void OnRender() = 0;
    };
} // OpenGameCore
