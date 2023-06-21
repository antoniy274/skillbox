# CMakeList.txt: проект CMake для lesson_32_1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lesson_32_1 "lesson_32_1.cpp" )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

target_link_libraries(lesson_32_1 PRIVATE nlohmann_json::nlohmann_json)