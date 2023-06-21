#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"

int main()
{
    std::ifstream file("C:/Users/anton/Desktop/skillbox/lesson_32_2/bin/films.json");

    nlohmann::json film;
    file >> film;
    if (!file.is_open())
    {
        std::cerr << "Unable to open file\n";
        throw 1;
    }
    file.close();
}