#include "ExampleGame.h"

#include <future>

#include "Engine.h"
#include "../Menu/MainMenu.h"

namespace TemplateGame
{
    ExampleGame::ExampleGame()
    {
        SetActiveMenu<MainMenu>(std::make_shared<MainMenu>(*this));

        // TODO (LinMAD): Move scene to engine
        m_Scene = OpenGameCore::Scene();
        m_Scene.ToggleIsPaused();
    }

    void ExampleGame::OnUpdate(const float deltaTime)
    {
        AbstractGameInstance::OnUpdate(deltaTime);
        if (m_ActiveMenu) return;

        if (IsKeyPressed(KEY_ESCAPE))
        {
            SetActiveMenu<MainMenu>(std::make_shared<MainMenu>(*this));
            return;
        }

        if (m_Scene.IsPaused()) return;

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            for (int i = 0; i < 10; i++) // Create more floppy disks :D
            {
                const auto floppy = m_Scene.CreateEntity<Floppy>(std::format("floppy-{}", i));
                m_FloppiesGUID.push_back(floppy->GetUUID());
            }
        }

        if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON))
        {
            const auto mousePos = GetMousePosition();
            const auto tol = 10.0f; // Tolerance - for matching

            // TODO (Arni): This is not optimised way and will drop FPS, improve later.
            for (auto it = m_FloppiesGUID.begin(); it != m_FloppiesGUID.end(); ++it) {
                {
                    const auto floppy = m_Scene.FindEntityByGUID<Floppy>(*it);
                    if (floppy == nullptr) continue;

                    const auto floppyPos = floppy->GetPosition();
                    const auto floppyTexture = GetTextureManager()->GetTexture(floppy->GetTextureID());
                    const auto isColliding = CheckCollisionPointRec(
                        mousePos,
                        {floppyPos.x + tol, floppyPos.y + tol, static_cast<float>(floppyTexture.width), static_cast<float>(floppyTexture.height)}
                    );
                    if (isColliding)
                    {
                        m_FloppiesGUID.erase(it);
                        m_Scene.DestroyEntity(floppy);
                        break;
                    }
                }
            }
        }

        // TODO (LinMAD): Move scene to engine
        m_Scene.OnUpdate(deltaTime);
    }

    void ExampleGame::OnRender()
    {
        AbstractGameInstance::OnRender();

        if (m_ActiveMenu) return;

        GetRenderer()->RenderText(
            "This is Template Game Example",
            5,
            20,
            30,
            0xff0000d3
        );
        GetRenderer()->RenderText(TextFormat(
            "Actors: %i", m_FloppiesGUID.size()),
            500,
            20,
            30,
            0xff00ffd3
        );

        if (!m_Scene.IsPaused())
        {
            m_Scene.OnRender();
        }
    }
} // namespace TemplateGame
