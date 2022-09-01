# CMakeList.txt: проект CMake для mobile_phone; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (mobile_phone "main.cpp" "mobile_phone.h" "mobile_phone.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
