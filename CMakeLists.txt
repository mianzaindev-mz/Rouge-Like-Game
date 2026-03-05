cmake_minimum_required(VERSION 3.16)
project(RogueEngine VERSION 0.2 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable
add_executable(RogueEngine src/main.cpp)

# Include directories
target_include_directories(RogueEngine PRIVATE include)

# Compiler warnings
if(MSVC)
    target_compile_options(RogueEngine PRIVATE /W4 /permissive-)
else()
    target_compile_options(RogueEngine PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install target
install(TARGETS RogueEngine DESTINATION bin)