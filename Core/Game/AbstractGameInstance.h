#pragma once
#include "EngineComponent.h"
#include "UI/AbstractMenu.h"

namespace OpenGameCore
{
    /**
     * @class AbstractGameInstance
     * @brief Represents an abstract game instance, providing a foundation for
     *        concrete game implementations to define their specific logic
     *        and interactions with the application.
     */
    class AbstractGameInstance : public EngineComponent
    {
    public:
        ~AbstractGameInstance() override;
        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        template<typename T>
        void SetActiveMenu(std::shared_ptr<T> menu)
        {
            m_ActiveMenu = menu;
        }
        template<typename T>
        std::shared_ptr<T> GetActiveMenu()
        {
           return m_ActiveMenu;
        }
    protected:
        std::shared_ptr<AbstractMenu> m_ActiveMenu;
    };
} // OpenGameCore
