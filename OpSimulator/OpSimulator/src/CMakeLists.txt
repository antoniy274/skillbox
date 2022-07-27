# CMakeList.txt: проект CMake для OpSimulator; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
project(OpSimulator VERSION 1.0)

# Добавьте источник в исполн"src/OpSimulator.cpp"проекта.
add_executable (OpSimulator OpSimulator.cpp ../include/OpSimulator.h)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
