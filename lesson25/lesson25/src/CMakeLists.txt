# CMakeList.txt: проект CMake для lesson25; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Я её сделал, но она отказывается работать
#set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lesson25 "lesson25.cpp" "../include/lesson25.h")
target_include_directories(lesson25 PUBLIC "lesson25/include")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
