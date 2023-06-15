cmake_minimum_required(VERSION 3.23)
project(pacman)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(pacman main.cpp Game.h Entity.h Walls.h Ghost.h Pacman.h Field.h Game.cpp Entity.cpp Field.cpp Ghost.cpp Pacman.cpp)

target_link_libraries(pacman sfml-graphics sfml-audio)
