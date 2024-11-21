#include "EngineComponent.h"
#include "Engine.h"

namespace OpenGameCore
{
    void EngineComponent::OnUpdate(float deltaTime)
    {
    }

    void EngineComponent::OnRender()
    {
    }

    std::shared_ptr<RenderingHandler> EngineComponent::GetRenderer()
    {
        return Engine::GetRendingHandler();
    }

    std::shared_ptr<TextureManager> EngineComponent::GetTextureManager()
    {
        return GetRenderer()->GetTextureManager();
    }
}// OpenGameCore
