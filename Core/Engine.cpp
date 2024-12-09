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

        InitWindow(
            m_Config.Width * m_Config.Scale,
            m_Config.Height * m_Config.Scale,
            m_Config.Title.c_str()
        );
    }

    Engine::~Engine()
    {
        s_Instance = nullptr;
    }

    void Engine::Run(const std::shared_ptr<AbstractGameInstance>& game)
    {
        m_Game = game;

        SetExitKey(0);
        SetTargetFPS(60);

        m_Icon = LoadImage(m_Config.IconPath.c_str());
        SetWindowIcon(m_Icon);

        m_LastTime = GetTime();

        while (!WindowShouldClose())
        {
            const double currentTime = GetTime();
            m_DeltaTime = currentTime - m_LastTime;
            m_LastTime = currentTime;

            OnUpdate();
            OnRender();
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
