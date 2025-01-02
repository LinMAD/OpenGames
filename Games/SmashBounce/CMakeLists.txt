cmake_minimum_required(VERSION 3.5)
project(SmashBounce)
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#
# Add executable
add_executable(${PROJECT_NAME}
        main.cpp

        Source/Game/SmashBounceGame.cpp
        Source/Game/SmashBounceGame.h

        Source/Scene/ArenaScene.cpp
        Source/Scene/ArenaScene.h

        Source/Menu/GameOverMenu.cpp
        Source/Menu/GameOverMenu.h

        Source/Entity/Paddle.cpp
        Source/Entity/Paddle.h
        Source/Entity/Ball.cpp
        Source/Entity/Ball.h
        Source/Entity/BlockSimple.cpp
        Source/Entity/BlockSimple.h
        Source/Entity/Score.cpp
        Source/Entity/Score.h
        Source/Entity/PickupItem.cpp
        Source/Entity/PickupItem.h
        Source/Entity/PickupItemMarbles.cpp
        Source/Entity/PickupItemMarbles.h

        Source/Constants/GameTags.h
        Source/Constants/ColorPicker.h
)
# Get the sources together
#
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_custom_target(${PROJECT_NAME}_CopyAssets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/assets
)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_CopyAssets)
#
# Link game project with OpenGameCore
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGameCore)
