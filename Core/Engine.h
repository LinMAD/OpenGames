#pragma once

#include <memory>
#include <string>

#include "raylib.h"

#include "Game/AbstractGameInstance.h"
#include "Graphics/RenderingHandler.h"

namespace OpenGameCore
{
    struct EngineConfig
    {
        // Window related
        int Width = 300;
        int Height = Width / 16 * 10;
        int Scale = 3;
        std::string Title = "Open Game Core";
        std::string IconPath = "assets/icon.png";
        // Window related

        bool DisplayFPS = true;
    };

    /**
     * @class Engine
     * @brief represents a core of game management.
     */
    class Engine
    {
    public:
        explicit Engine(EngineConfig cfg = EngineConfig());
        ~Engine();

        /**
         * Run game in Engine.
         * @param game Implementation
         */
        void Run(const std::shared_ptr<AbstractGameInstance>& game);

        /**
         * Updates Engine and Game state.
         */
        void OnUpdate();

        /**
         * Renders frame on screen.
         */
        void OnRender();

    public:
        /**
         * @return Engine instance as singleton.
         */
        static Engine& Get();

        /**
         * @return RenderingHandler.
         */
        static std::shared_ptr<RenderingHandler> GetRendingHandler() { return Get().m_RenderingHandler; };

    private:
        double m_DeltaTime = 0.0;   // Time elapsed since the last frame
        double m_LastTime = 0.0;    // Tracks the last frame's timestamp


        EngineConfig m_Config;
        std::shared_ptr<RenderingHandler> m_RenderingHandler;
        std::shared_ptr<AbstractGameInstance> m_Game;
        Image m_Icon{};
    };
} // OpenGameCore
