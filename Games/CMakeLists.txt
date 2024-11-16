# ----------------------------------------------------------------------
# All game implementation
# ----------------------------------------------------------------------
set(game_directories
        Template
)
set(game_sources)
set(game_resources)

#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

# ----------------------------------------------------------------------
# raylib dependency
# ----------------------------------------------------------------------
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG ae50bfa2cc569c0f8d5bc4315d39db64005b1b08
            GIT_SHALLOW 1
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# ----------------------------------------------------------------------
# Find all games
# ----------------------------------------------------------------------
foreach(game_dir ${game_directories})
    file(GLOB sources ${game_dir}/*.cpp)
    list(APPEND game_sources ${sources})

    # Append assets
    file(GLOB assets ${game_dir}/assets/*)
    list(APPEND game_sources ${assets})
endforeach()

# ----------------------------------------------------------------------
# Compile all examples
# ----------------------------------------------------------------------
foreach(game_source ${game_sources})
    get_filename_component(game_title ${game_source} NAME)
    string(REPLACE ".cpp" "${OUTPUT_EXT}" game_title ${game_title})

    add_executable(${game_title} ${game_source})

    # Link dependencies
    target_link_libraries(${game_title} PUBLIC raylib open_game_core)

    string(REGEX MATCH ".*/.*/" assets_dir ${game_source})
    string(APPEND assets_dir "assets")
endforeach()

# Copy all the resources
file(COPY ${game_resources} DESTINATION "assets/")
