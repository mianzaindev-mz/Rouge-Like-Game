cmake_minimum_required(VERSION 3.15)
project(RogueEngine VERSION 0.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(RogueEngine
    src/main.cpp
    src/player.cpp
    src/renderer.cpp
    src/map.cpp
    src/enemy.cpp
)

target_include_directories(RogueEngine PRIVATE include)