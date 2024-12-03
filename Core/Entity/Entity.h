#pragma once
#include "EngineComponent.h"

namespace OpenGameCore
{
    /**
     * @class Entity
     * @brief Entity that might be used in a game, like player or another actor.
     */
    class Entity : public EngineComponent
    {
    public:
        Entity(const std::string& tagName, const std::string& uuid);

        /**
         * @brief Set Entity tag name.
         * @param tagName
         */
        void SetTag(const std::string& tagName);

        /**
         * @return string
         */
        [[nodiscard]] std::string GetTag() const { return m_Tag; }

        /**
         * @return string
         */
        [[nodiscard]] std::string GetUUID() const { return m_UUID; }

    protected:
        std::string m_Tag;
        std::string m_UUID;
    };
} // OpenGameCore
