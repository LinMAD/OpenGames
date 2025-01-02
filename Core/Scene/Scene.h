#pragma once

#include <ranges>

#include "EngineComponent.h"
#include "Entity/Entity.h"
#include "Generators/UuidGenerator.h"

namespace OpenGameCore
{
    /**
     * @class Scene
     * @brief Scene Graph that allows render world and all entities.
     */
    class Scene : public EngineComponent
    {
    public:
        Scene();
        ~Scene() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        /**
         * @tparam T Any Entity implementation.
         * @param name tag
         * @return Entity
         */
        template <typename T>
        std::shared_ptr<T> CreateEntity(const std::string& name)
        {
            auto newEntity = std::make_shared<T>(name, UuidGenerator().Generate());
            m_Entities[newEntity->GetUUID()] = newEntity;

            return newEntity;
        }

        /**
         * Find Entity located in the scene that is matching TAG.
         * @tparam T
         * @param name
         * @return Entity that was found first.
         */
        template <typename T>
        std::shared_ptr<T> FindFirstEntityByName(const std::string_view name)
        {
            for (auto entity : m_Entities | std::views::values)
            {
                if (entity != nullptr && entity->GetTag() == name)
                {
                    return std::dynamic_pointer_cast<T>(entity);
                }
            }

            return {};
        }

        /**
         * Find Entity located in the scene.
         * @tparam T
         * @param GUID
         * @return Entity
         */
        template <typename T>
        std::shared_ptr<T> FindEntityByGUID(const std::string_view GUID)
        {
            for (auto entity : m_Entities)
            {
                if (entity.first == GUID)
                {
                    return std::dynamic_pointer_cast<T>(entity.second);
                }
            }

            return {};
        }

        /**
         * @brief Remove given entity from scene.
         * @param entity
         */
        template <typename T>
        void DestroyEntity(const std::shared_ptr<T>& entity)
        {
            m_Entities.erase(entity->GetUUID());
        }

        [[nodiscard]] bool IsPaused() const { return m_IsPaused; }

        void ToggleIsPaused() { m_IsPaused = !m_IsPaused; }

    protected:
        bool m_IsPaused = true;

        std::unordered_map<std::string, std::shared_ptr<Entity>> m_Entities; // UUID + Entity
    };
} // OpenGameCore
