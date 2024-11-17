#pragma once

#include <memory>
#include <string>

#include "Game/GameInstance.h"
#include "raylib.h"

namespace OpenGameCore
{
    struct ApplicationConfig
    {
        int Width = 300;
        int Height = Width / 16 * 10;
        int Scale = 3;
        std::string Title = "Open Game Core";
        std::string IconPath = "assets/icon.png";
    };

    /// Application core handler of game management.
    class Application
    {
    public:
        Application(const ApplicationConfig& cfg = ApplicationConfig());
        ~Application();

        void Run(std::unique_ptr<GameInstance> game);
        void OnUpdate();
        void OnRender();

    private:
        const float m_DeltaTime = 0.01667f;

        double m_LastTime = 0;
        float m_Time = 0.0f;

        ApplicationConfig m_AppCfg;
        Image m_Icon;
        std::unique_ptr<GameInstance> m_Game;
    };
} // OpenGameCore
