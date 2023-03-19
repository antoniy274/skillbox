# CMakeList.txt: проект CMake для lesson30.1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(BUILD_CPR_TEST OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


# Добавьте источник в исполняемый файл этого проекта.
add_executable (lesson30.1 "lesson30.1.cpp" "lesson30.1.h")
target_link_libraries(lesson30.1 PRIVATE cpr::cpr)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
