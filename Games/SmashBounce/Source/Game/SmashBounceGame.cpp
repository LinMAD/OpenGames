#include "SmashBounceGame.h"

#include "../Menu/GameOverMenu.h"
#include "../Constants/GameTags.h"

// TODO (LinMAD): Replace shapes by textures

namespace SmashBounce
{
    SmashBounceGame::SmashBounceGame()
    {
        GetRenderer()->AddFont("assets/fonts/CAT-Arena.ttf");
        // TODO ADD Simple Main menu
        Restart();
    }

    SmashBounceGame::~SmashBounceGame()
    {
        delete m_SceneArena;
    }

    void SmashBounceGame::OnUpdate(const float deltaTime)
    {
        AbstractGameInstance::OnUpdate(deltaTime);

        if (IsGamePaused()) return;

        m_SceneArena->OnUpdate(deltaTime); // Update rest of the scene

        if (IsGameOver()) return;
    }

    void SmashBounceGame::OnRender()
    {
        AbstractGameInstance::OnRender();

        if (m_ActiveMenu) return;

        m_SceneArena->OnRender();
    }

    void SmashBounceGame::Restart()
    {
        m_ActiveMenu = nullptr;
        m_SceneArena = new ArenaScene(*this);
        m_SceneArena->ToggleIsPaused();
    }

    bool SmashBounceGame::IsGamePaused()
    {
        if (m_ActiveMenu) return true;

        if (m_SceneArena->IsPaused()) return true;

        return false;
    }

    bool SmashBounceGame::IsGameOver()
    {
        if (m_SceneArena->IsGameOver())
        {
            SetActiveMenu<GameOverMenu>(std::make_shared<GameOverMenu>(*this));
            return true;
        }

        const auto playerMarbles = m_SceneArena->FindEntitiesByName<Ball>(TAG_PLAYER_BALL);
        bool isPlayerLostMarbles = playerMarbles.empty();

        for (const auto& marble : playerMarbles)
        {
            if (marble->GetPosition().y > GetRenderer()->GetHeightWithScale())
            {
                m_SceneArena->DestroyEntity(marble);
            }
            else
            {
                isPlayerLostMarbles = false;
            }
        }


        return m_SceneArena->SetIsGameOver(isPlayerLostMarbles);
    }
} // SmashBounce
