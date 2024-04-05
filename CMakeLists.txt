cmake_minimum_required(VERSION 3.27)
project(maze_escape)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(test-unit)

add_executable(maze_escape
        src/maze_escape.h
        test-unit/catch.hpp
        test-unit/test.cpp)
