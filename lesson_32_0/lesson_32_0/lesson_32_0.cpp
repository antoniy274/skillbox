#include <iostream>
#include <string>
#include <fstream>

struct Record
{
	std::string name;
	std::string family;
	int age;
};

int main()
{
	Record record;
	std::cin >> record.name >> record.family >> record.age;
	std::ofstream file("record.json");
	file << "{" << "\"name\": \"" << record.name << "\", \"family\": \"" << record.family << "\"}" << std::endl;
}
