#include <iostream>
#include <thread>
#include <ctime>
#include <map>

void hundred_meters(float speed, std::string name);

int main()
{
	hundred_meters(15.2, "Felps");
}

void hundred_meters(float speed, std::string name) {
	std::time_t t;
	t = 100 / speed;
	auto i = 0;
	float s = 0;
	while (s <= 100 && i != t)
	{
		s += speed * i;
		std::cout << name << s << "\n";
		i++;
	}
}