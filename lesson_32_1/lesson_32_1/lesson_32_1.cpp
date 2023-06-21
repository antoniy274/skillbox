#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

struct Film
{
	std::string name;
	std::string director;
	std::string writer;
	std::string actors;
	std::string producers;
	std::string date;
	std::string country;
	std::string studio;
};

int main()
{
	Film film;
	std::ifstream file("film.json");
	nlohmann::json dict;
	file >> dict;
	film.name = dict["Original title"];
	film.director = dict["Director"];
	film.writer = dict["Writer"];
	film.actors = dict["Actors"];
	film.producers = dict["Producers"];
	film.date = dict["World Premiere"];
	film.country = dict["Country"];
	film.studio = dict["Studio"];

	std::cout << film.name << std::endl;
	std::cout << film.director << std::endl;
	std::cout << film.writer << std::endl;
	std::cout << film.actors << std::endl;
	std::cout << film.producers << std::endl;
	std::cout << film.date << std::endl;
	std::cout << film.country << std::endl;
	std::cout << film.studio << std::endl;
}