# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

project ("lesson_35_3")

# Включите подпроекты.
add_subdirectory ("lesson_35_3")
