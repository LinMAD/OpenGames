#include "SmashBounce.h"

#include "../Entity/Paddle.h"

namespace SmashBounce
{
    SmashBounceGame::SmashBounceGame()
    {
        m_SceneArena = ArenaScene();
        m_SceneArena.CreateEntity<Paddle>(m_TagPlayer);
        m_SceneArena.ToggleIsPaused();
    }

    void SmashBounceGame::OnUpdate(const float deltaTime)
    {
        AbstractGameInstance::OnUpdate(deltaTime);

        if (!m_SceneArena.IsPaused())
        {
            m_SceneArena.OnUpdate(deltaTime);
        }
    }

    void SmashBounceGame::OnRender()
    {
        AbstractGameInstance::OnRender();

        m_SceneArena.OnRender();
    }
} // Template
