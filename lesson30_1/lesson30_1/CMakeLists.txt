# CMakeList.txt: проект CMake для lesson30_1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lesson30_1 "lesson30_1.cpp" "lesson30_1.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(lesson30_1 PRIVATE cpr::cpr)
