# CMakeList.txt: проект CMake для lesson30_3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lesson30_3 "lesson30_3.cpp" )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(lesson30_3 PRIVATE cpr::cpr)