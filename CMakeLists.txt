cmake_minimum_required(VERSION 3.19)
project(pacman)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(pacman main.cpp Engine.cpp Engine.h)
target_link_libraries(pacman ${CURSES_LIBRARIES})