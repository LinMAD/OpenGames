#include "SmashBounceGame.h"

#include "../Menu/GameOverMenu.h"

// TODO (LinMAD): Add Score system + add speed to the ball
// TODO (LinMAD): Replace shapes by textures

namespace SmashBounce
{
    SmashBounceGame::SmashBounceGame()
    {
        GetRenderer()->AddFont("assets/fonts/GAME_glm.ttf");

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

        // Game Pause or Game over
        {
            if (m_ActiveMenu) return;

            if (m_SceneArena->IsPaused())
            {
                return;
            }
            if (m_SceneArena->IsGameOver())
            {
                SetActiveMenu<GameOverMenu>(std::make_shared<GameOverMenu>(*this));
                return;
            }
        }

        m_SceneArena->OnUpdate(deltaTime); // Update rest of the scene

        // Player lost a ball?
        const auto playersBall = m_SceneArena->FindEntityByName<Ball>(m_TagPlayerBall);
        if (m_SceneArena->SetIsGameOver(playersBall->GetPosition().y > GetRenderer()->GetHeightWithScale())) return;
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
} // Template
