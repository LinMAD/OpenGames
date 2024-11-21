#include "AbstractGameInstance.h"

namespace OpenGameCore
{
    AbstractGameInstance::~AbstractGameInstance()= default;

    void AbstractGameInstance::OnUpdate(const float deltaTime)
    {
        EngineComponent::OnUpdate(deltaTime);

        if (m_ActiveMenu)
        {
            m_ActiveMenu->OnUpdate(deltaTime);
        }
    }

    void AbstractGameInstance::OnRender()
    {
        EngineComponent::OnRender();

        if (m_ActiveMenu)
        {
            m_ActiveMenu->OnRender();
        }
    }
} // OpenGameCore
