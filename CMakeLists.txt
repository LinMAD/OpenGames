cmake_minimum_required(VERSION 3.5)
project (OpenGames
        VERSION 0.1.0
        DESCRIPTION "OpenGame is collection of simple games made with raylib"
        HOMEPAGE_URL "https://github.com/LinMAD/OpenGames"
        LANGUAGES C CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------------------------------------------
# Open Games Core
# ----------------------------------------------------------------------
add_subdirectory(Core)
# ----------------------------------------------------------------------
# Games Implementations
# ----------------------------------------------------------------------
file(GLOB SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR}/Games ${CMAKE_SOURCE_DIR}/Games/*)
foreach(subdir ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/Games/${subdir})
        add_subdirectory(Games/${subdir})
    endif()
endforeach()
