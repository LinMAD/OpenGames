#include "SampleGame.h"

#include <iostream>
#include <ostream>

namespace TemplateGame {

    void SampleGame::OnUpdate(float deltaTime) {
        std::cout << "Updating game with deltaTime: " << deltaTime << std::endl;
    }

    void SampleGame::OnRender() {
        std::cout << "Rendering the game..." << std::endl;
    }

} // namespace TemplateGame