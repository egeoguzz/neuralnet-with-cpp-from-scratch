cmake_minimum_required(VERSION 3.31)
project(tinynet)

set(CMAKE_CXX_STANDARD 20)

add_executable(tinynet main.cpp
        Matrix.cpp
        Matrix.h)
