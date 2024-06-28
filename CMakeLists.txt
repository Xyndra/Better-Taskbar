cmake_minimum_required(VERSION 3.28)
project(better_taskbar)

set(CMAKE_CXX_STANDARD 17)

add_executable(better_taskbar main.cpp
        main.h
        hider.cpp
        hider.h)
