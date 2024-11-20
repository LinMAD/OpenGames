#pragma once

namespace OpenGameCore
{
    /**
     * @class AbstractEntity
     * @brief Abstract entity that might be used in a game, like player or another actor.
     */
    class AbstractEntity
    {
    public:
        virtual ~AbstractEntity() = default;

        /***
         * @brief Called inside Engine when update must be done.
         */
        virtual void OnUpdate(float delta) = 0;
        /***
         * @brief Called inside Engine when screen render will be called.
         */
        virtual void OnRender() = 0;
    };
} // OpenGameCore
