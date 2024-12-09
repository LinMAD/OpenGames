#include "SmashBounce.h"

// TODO (LinMAD): Add UI
// TODO (LinMAD): Add Score system + add speed to the ball
// TODO (LinMAD): Replace shapes by textures

namespace SmashBounce
{
    SmashBounceGame::SmashBounceGame()
    {
        const auto rend = GetRenderer();
        rend->AddFont("assets/fonts/GAME_glm.ttf");

        m_DefaultTextHeight = 60;
        m_TextWidth = MeasureText(m_Text, m_DefaultTextHeight);
        m_TextPosition = Vector2{
            (rend->GetWidthWithScale() - static_cast<float>(m_TextWidth)) / 2.0f,
            (rend->GetHeightWithScale() - static_cast<float>(m_DefaultTextHeight)) / 2.0f
        };

        m_SceneArena = new ArenaScene(*this);

        // TODO (LinMAD): Add UI to start game
        m_SceneArena->ToggleIsPaused();
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
            if (m_SceneArena->IsPaused())
            {
                return;
            }
            if (m_SceneArena->IsGameOver())
            {
                GetRenderer()->RenderText(
                    m_Text,
                    static_cast<int>(m_TextPosition.x),
                    static_cast<int>(m_TextPosition.y),
                    m_DefaultTextHeight,
                    0x722F37FF
                );
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

        m_SceneArena->OnRender();
    }
} // Template
