cmake_minimum_required (VERSION 3.8)

set(SOURCES main.cpp shared_ptr_toy.cpp)


add_executable(lesson_31_1 ${SOURCES})

target_include_directories(lesson_31_1 PUBLIC ${MY_INCLUDE_DIR})