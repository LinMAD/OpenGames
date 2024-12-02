#pragma once
#include "EngineComponent.h"
#include "Entity/Entity.h"
#include "Generators/UUID.h"

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
         * @tparam T Any Entity implementation
         * @param name tag
         * @return Entity
         */
        template <typename T>
        std::shared_ptr<T> CreateEntity(const std::string& name)
        {
            auto newEntity = std::make_shared<T>(name, UUID().Generate());
            m_Entities[newEntity->GetUUID()] = newEntity;

            return newEntity;
        }

        /**
         * @brief Remove given entity from scene
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
