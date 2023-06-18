#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"


struct Record
{
	std::string name;
	std::string family;
	int age;
	bool married;
};

int main()
{
	Record record;
	std::ifstream file("record.json");
	nlohmann::json dict;
	file >> dict;
	record.name = dict["name"];
	record.family = dict["family"];
	record.age = dict["age"];
	record.married = dict["married"];
	std::cout << record.name << " " << record.family << " " << record.age << " " << record.married << std::endl;
}
