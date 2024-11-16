cmake_minimum_required(VERSION 3.28.1)

project (OpenGames
        VERSION 0.1.0
        DESCRIPTION "OpenGame is collection of simple games made with raylib"
        HOMEPAGE_URL "https://github.com/LinMAD/OpenGames"
        LANGUAGES C CXX
)

# ----------------------------------------------------------------------
# Open Games Core
# ----------------------------------------------------------------------
add_subdirectory(Core)

# ----------------------------------------------------------------------
# Games source code
# ----------------------------------------------------------------------
add_subdirectory(Games)
set(BUILD_RAYLIB_CPP_STATIC ON)
