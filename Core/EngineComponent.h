#pragma once
#include "Graphics/TextureManager.h"
#include "Graphics/RenderingHandler.h"

namespace OpenGameCore
{
    /**
    * @class EngineComponent
    * @breif An abstract class designed to manage and encapsulate the lifecycle of an object
    */
    class EngineComponent
    {
    public:
        virtual ~EngineComponent() = default;
        /***
         * @brief Called inside Engine when update must be done.
         */
        virtual void OnUpdate(float deltaTime);
        /***
         * @brief Called inside Engine when screen render will be called.
         */
        virtual void OnRender();

    protected:
        static std::shared_ptr<RenderingHandler> GetRenderer();
        static std::shared_ptr<TextureManager> GetTextureManager();
    };
} // OpenGameCore
