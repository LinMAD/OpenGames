cmake_minimum_required(VERSION 3.5)
project(Demo)
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#
# Add executable
add_executable(${PROJECT_NAME}
        main.cpp

        Source/Game/ExampleGame.cpp

        Source/Entity/Floppy.cpp

        Source/Menu/MainMenu.cpp
        Source/Menu/MainMenu.h
        Source/Menu/AboutMenu.cpp
        Source/Menu/AboutMenu.h
)
# Get the sources together
#
# Find assets
file(GLOB game_assets ${CMAKE_CURRENT_SOURCE_DIR}/assets/*)
list(APPEND game_assets ${game_assets})
#
# Copy all the resources
file(COPY ${game_assets} DESTINATION "assets/")
#
# Link game project with OpenGameCore
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGameCore)
