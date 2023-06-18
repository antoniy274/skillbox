# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("lesson_32_0")

set(JSON_BuildTests OFF CACHE INTERNAL "")


# Включите подпроекты.
add_subdirectory ("lesson_32_0")

add_subdirectory("nlohmann_json")