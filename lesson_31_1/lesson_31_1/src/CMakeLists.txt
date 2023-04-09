cmake_minimum_required (VERSION 3.8)

# Я её сделал, но она отказывается работать
#set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lesson_31_1 "main.cpp" "../include/shared_ptr_toy.h" "shared_ptr_toy.cpp")
target_include_directories(lesson_31_1 PUBLIC "lesson25/include")