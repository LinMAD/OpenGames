#include "raylib.h"
#include "Application.h"

namespace OpenGameCore
{
    static Application* s_Instance = nullptr;

    Application::Application(const ApplicationConfig& cfg) : m_AppCfg(cfg)
    {
        s_Instance = this;
    }

    Application::~Application()
    {
        s_Instance = nullptr;
    }

    void Application::Run(std::unique_ptr<GameInstance> game)
    {
        m_Game = std::move(game);
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

    void Application::OnUpdate()
    {
        m_Game->OnUpdate(m_DeltaTime);
    }

    void Application::OnRender()
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        m_Game->OnRender();

        EndDrawing();
    }
} // OpenGameCore