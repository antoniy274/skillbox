cmake_minimum_required(VERSION 3.20)
project(PC VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_PATH "../include/")

add_executable(25_2_PC
        main.cpp
        cpu.cpp
        disk.cpp
        gpu.cpp
        kbd.cpp
        ram.cpp
        ${INCLUDE_PATH}cpu.h
        ${INCLUDE_PATH}ram.h
        ${INCLUDE_PATH}disk.h
        ${INCLUDE_PATH}gpu.h
        ${INCLUDE_PATH}kbd.h)