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
        static RenderingHandler& GetRendingHandler() { return Get().m_RenderingHandler; };

    private:
        const float m_DeltaTime = 0.01667f;

        double m_LastTime = 0;
        float m_Time = 0.0f;

        EngineConfig m_Config;
        RenderingHandler m_RenderingHandler;
        std::shared_ptr<AbstractGameInstance> m_Game;
        Image m_Icon{};
    };
} // OpenGameCore
