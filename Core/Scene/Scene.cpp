#include "Scene.h"

#include <ranges>

#include "Entity/Entity.h"

namespace OpenGameCore {
    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
        m_Entities.clear();
    }

    void Scene::OnUpdate(const float deltaTime)
    {
        EngineComponent::OnUpdate(deltaTime);

        if (!m_IsPaused)
        {
            for (const auto& entity : m_Entities | std::views::values)
            {
                entity->OnUpdate(deltaTime);
            }
        }
    }

    void Scene::OnRender()
    {
        EngineComponent::OnRender();

        if (!m_IsPaused)
        {
            for (const auto& entity : m_Entities | std::views::values)
            {
                entity->OnRender();
            }
        }
    }
} // OpenGameCore