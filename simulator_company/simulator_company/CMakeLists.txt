# CMakeList.txt: проект CMake для simulator_company; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (simulator_company "simulator_company.cpp" "simulator_company.h" "main.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
