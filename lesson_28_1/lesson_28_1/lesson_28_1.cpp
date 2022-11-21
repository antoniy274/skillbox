#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include <mutex>

void sprintHundred(std::string name, double speed);

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

	std::thread firstTrack(sprintHundred, swimmer[0].name, swimmer[0].speed);
	std::thread secondTrack(sprintHundred, swimmer[1].name, swimmer[1].speed);
	std::thread thirdTrack(sprintHundred, swimmer[2].name, swimmer[2].speed);
	std::thread fourTrack(sprintHundred, swimmer[3].name, swimmer[3].speed);
	std::thread fiveTrack(sprintHundred, swimmer[4].name, swimmer[4].speed);
	std::thread sixTrack(sprintHundred, swimmer[5].name, swimmer[5].speed);

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

void sprintHundred(std::string name, double speed) {
	double time;
	time = 100 / speed;
	auto i = 0;
	double distance = speed;
	while (distance <= 100 && i != time)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));

		dashboard_swimmer.lock();
		std::cout << name << " " << distance << "\n";
		dashboard_swimmer.unlock();

		distance += speed;
		i++;
	}
	distance -= speed;
	distance += ((time - (int)time) * speed);
	dashboard_swimmer.lock();
	std::cout << name << " " << distance << "\n";
	dashboard_swimmer.unlock();
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