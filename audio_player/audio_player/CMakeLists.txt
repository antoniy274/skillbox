# CMakeList.txt: проект CMake для audio_player; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (audio_player "main.cpp" "audio_player.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
