﻿# CMakeList.txt: проект CMake для elf_village; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (elf_village "main.cpp" "elf_village.h" "elf_village.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
