# CMakeList.txt: проект CMake для PC_Simulator; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (PC_Simulator "main.cpp"
"../include/cpu.h" "../include/disk.h" "../include/gpu.h" "../include/kbd.h" "../include/ram.h"
"cpu.cpp" "disk.cpp" "gpu.cpp" "kbd.cpp" "ram.cpp")
target_include_directories(PC_Simulator PUBLIC "PC_Simulator/include")
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
