# CMakeList.txt: проект CMake для lesson_31_2_1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lesson_31_2_1 "main.cpp" "../include/igraph.h" "../include/listgraph.h" "../include/matrixgraph.h" "listgraph.cpp" "matrix.cpp")
target_include_directories(lesson_31_2_1 PUBLIC "lesson_31_2_1/include")
