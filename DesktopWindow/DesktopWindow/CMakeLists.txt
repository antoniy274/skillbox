﻿# CMakeList.txt: проект CMake для DesktopWindow; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (DesktopWindow "main.cpp" "DesktopWindow.h" "DesktopWindow.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
