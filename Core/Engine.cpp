#include "raylib.h"
#include "Engine.h"

#include <utility>

namespace OpenGameCore
{
    static Engine* s_Instance = nullptr;

    Engine::Engine(EngineConfig cfg): m_Config(std::move(cfg))
    {
        s_Instance = this;
        m_RenderingHandler = std::make_shared<RenderingHandler>(cfg.Width, cfg.Height, cfg.Scale);
    }

    Engine::~Engine()
    {
        s_Instance = nullptr;
    }

    void Engine::Run(const std::shared_ptr<AbstractGameInstance>& game)
    {
        m_Game = game;

        InitWindow(
            m_Config.Width * m_Config.Scale,
            m_Config.Height * m_Config.Scale,
            m_Config.Title.c_str()
        );

        SetExitKey(0);
        SetTargetFPS(60);

        m_Icon = LoadImage(m_Config.IconPath.c_str());
        SetWindowIcon(m_Icon);

        m_LastTime = GetTime();

        while (!WindowShouldClose())
        {
            m_Time += m_DeltaTime;
            OnUpdate();
            OnRender();

            while (GetTime() - m_LastTime > 1.0)
            {
                m_LastTime++;
            }
        }

        CloseAudioDevice();
        CloseWindow();
        UnloadImage(m_Icon);
    }

    void Engine::OnUpdate()
    {
        m_Game->OnUpdate(m_DeltaTime);
    }

    void Engine::OnRender()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (m_Config.DisplayFPS)
        {
            GetRendingHandler()->RenderText(
                TextFormat("FPS: %i", GetFPS()), 5, 0, 20, 0xcc33ff
            );
        }

        m_Game->OnRender();

        EndDrawing();
    }

    Engine& Engine::Get()
    {
        return *s_Instance;
    }
} // OpenGameCore