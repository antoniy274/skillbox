#include <iostream>
#include <thread>
#include <ctime>
#include <vector>
#include <map>

void hundred_meters(double speed, std::string name);
std::map<double, std::string> list_swimmer;

struct Swimmer
{
	std::string name;
	int speed;
};

int main()
{
	std::string name;
	int speed;
	std::cout << "Enter swimming name: ";
	std::cin >> name;
	std::cout << "Enter swimming speed: ";
	std::cin >> speed;
	std::thread firstTrack(speed, name);

	std::cout << "Enter swimming name: ";
	std::cin >> name;
	std::cout << "Enter swimming speed: ";
	std::cin >> speed;
	std::thread secondTrack(speed, name);

	std::cout << "Enter swimming name: ";
	std::cin >> name;
	std::cout << "Enter swimming speed: ";
	std::cin >> speed;
	std::thread thirdTrack(speed, name);

	std::cout << "Enter swimming name: ";
	std::cin >> name;
	std::cout << "Enter swimming speed: ";
	std::cin >> speed;
	std::thread fourTrack(speed, name);

	firstTrack.join();
	secondTrack.join();
	thirdTrack.join();
	fourTrack.join();
}

void hundred_meters(double speed, std::string name) {
	double t;
	t = 100 / speed;
	auto i = 0;
	double s = speed;
	while (s <= 100 && i != t)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << name << " " << s << "\n";
		s += speed;
		i++;
	}
	s -= speed;
	s += ((t - (int)t) * speed);
	std::cout << name << " " << s << "\n";
	std::pair<int, std::string> sw;
	//list_swimmer.insert(sw);
}