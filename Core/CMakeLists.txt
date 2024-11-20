cmake_minimum_required(VERSION 3.5)
project(OpenGameCore)
# ----------------------------------------------------------------------
# Define source code as library
# ----------------------------------------------------------------------
add_library(${PROJECT_NAME} STATIC
        Engine.cpp
        Engine.h

        Game/AbstractGameInstance.h

        Graphics/RenderingHandler.cpp
        Graphics/RenderingHandler.h
        Graphics/TextureManager.cpp
        Graphics/TextureManager.h

        Entity/AbstractEntity.h
)
# ----------------------------------------------------------------------
# raylib dependency
# ----------------------------------------------------------------------
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif ()
endif ()
#
# Linking
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
