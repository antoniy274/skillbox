#include <iostream>
#include <algorithm>
#include <thread>
#include <ctime>
#include <vector>
#include <map>
#include <mutex>

void hundred_meters(std::string name, double speed);
std::map<double, std::string> list_swimmer;
std::mutex dashboard_swimmer;

struct Swimmer
{
	std::string name;
	double speed;
	double time = 100 / speed;
};

void sortirovka(std::vector<Swimmer> swimmer);

int main()
{
	std::vector<Swimmer> swimmer;
	for (int i = 0; i < 6; ++i) {
		Swimmer example;
		std::cin >> example.name >> example.speed;
		swimmer.push_back(example);
	}

	std::thread firstTrack(hundred_meters, swimmer[0].name, swimmer[0].speed);
	std::thread secondTrack(hundred_meters, swimmer[1].name, swimmer[1].speed);
	std::thread thirdTrack(hundred_meters, swimmer[2].name, swimmer[2].speed);
	std::thread fourTrack(hundred_meters, swimmer[3].name, swimmer[3].speed);
	std::thread fiveTrack(hundred_meters, swimmer[4].name, swimmer[4].speed);
	std::thread sixTrack(hundred_meters, swimmer[5].name, swimmer[5].speed);

	firstTrack.join();
	secondTrack.join();
	thirdTrack.join();
	fourTrack.join();
	fiveTrack.join();
	sixTrack.join();

	sortirovka(swimmer);

	for (int i = 0; i < swimmer.size(); ++i) {
		std::cout << i + 1 << " Name: " << swimmer[i].name << " Time " << swimmer[i].time << "\n";
	}
}

void hundred_meters(std::string name, double speed) {
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
	std::pair<int, std::string> sw(t, name);
	//dashboard_swimmer.lock();
	//for (int i = 0; i < 6; ++i) {
		//swimmer[i].time = t;
	//}
	//dashboard_swimmer.unlock();
}

void sortirovka(std::vector<Swimmer> swimmer) {
	for (int i = 0; i < swimmer.size(); ++i){
		bool flag = false;
		for (int j = 0; j < swimmer.size() - i; ++j) {
			if (swimmer[j].time > swimmer[j + 1].time) {
				auto temp = swimmer[j].time;
				swimmer[j].time = swimmer[j + 1].time;
				swimmer[j + 1].time = temp;
				flag = true;
			}
			if (flag == false)
				break;
		}
	}
}