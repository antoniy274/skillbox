#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

#define COMMAND_ONE "Arrival at the station"
#define COMMAND_TWO "Waiting for free space"
#define COMMAND_THREE "Departure from the station"

std::mutex activitiesStation;
void railwayStation(std::string name, int time);

struct Train
{
	std::string name;
	int time = 0;
};

int main()
{
	std::vector<Train> train;
	for (int i = 0; i < 3; ++i) {
		Train example;
		std::cin >> example.name >> example.time;
		train.push_back(example);
	}

	std::thread firstTrain(railwayStation, train[0].name, train[0].time);
	std::thread secondTrain(railwayStation, train[1].name, train[1].time);
	std::thread thirdTrain(railwayStation, train[2].name, train[2].time);

	firstTrain.join();
	secondTrain.join();
	thirdTrain.join();
}

void railwayStation(std::string name, int time) {
	activitiesStation.lock();
	std::cout << name << " " << COMMAND_ONE << "\n";
	activitiesStation.unlock();

	std::this_thread::sleep_for(std::chrono::seconds(time));
	activitiesStation.lock();
	std::cout << name << " " << COMMAND_TWO << "\n";
	activitiesStation.unlock();

	std::string command;
	activitiesStation.lock();
	std::cout << "Enter command (depart) to send: ";
	while (std::cin>>command)
	{
		if (command == "depart") {
			std::cout << name << " " << COMMAND_THREE << "\n";
			break;
		}
	}
	activitiesStation.unlock();
}