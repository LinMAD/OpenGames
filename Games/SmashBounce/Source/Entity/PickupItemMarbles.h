#pragma once

#include "PickupItem.h"

namespace SmashBounce
{
    class PickupItemMarbles final : public PickupItem
    {
    public:
        PickupItemMarbles(const std::string& tagName, const std::string& uuid);

        void OnUpdate(float deltaTime) override;
        void OnRender() override;

        bool GetIsActive() const;

        void SetActive(bool active);
        void SetNewPosition(Vector2 position);
    };
} // SmashBounce
