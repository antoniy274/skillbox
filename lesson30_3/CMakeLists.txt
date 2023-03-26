# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required (VERSION 3.8)

project ("lesson30_3")

set(BUILD_CPR_TEST OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) 
# The commit hash for 1.10.x. Replace with the latest from
FetchContent_MakeAvailable(cpr)

# Включите подпроекты.
add_subdirectory ("lesson30_3")
