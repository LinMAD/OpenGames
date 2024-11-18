#include "raylib.h"
#include "Engine.h"

#include <utility>

namespace OpenGameCore
{
    static Engine* s_Instance = nullptr;

    Engine::Engine(EngineConfig cfg)
        : m_AppCfg(std::move(cfg)), m_RenderingHandler(cfg.Width, cfg.Height)
    {
        s_Instance = this;
    }

    Engine::~Engine()
    {
        s_Instance = nullptr;
    }

    void Engine::Run(const std::shared_ptr<GameInstance>& game)
    {
        m_Game = game;

        InitWindow(m_AppCfg.Width * m_AppCfg.Scale, m_AppCfg.Height * m_AppCfg.Scale, m_AppCfg.Title.c_str());
        SetExitKey(0);
        SetTargetFPS(60);

        m_Icon = LoadImage(m_AppCfg.IconPath.c_str());
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

        m_Game->OnRender();

        EndDrawing();
    }

    Engine& Engine::Get()
    {
        return *s_Instance;
    }
} // OpenGameCore