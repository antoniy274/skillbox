#include "example28.1.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>

std::vector<std::string> history;
std::mutex history_access;

void wait_for_call(int time, std::string name)
{
	std::this_thread::sleep_for(std::chrono::seconds(time));

	std::cout << "RING (" << name << ")" << "\n";
	
	history_access.lock();
	history.push_back(name);
	history_access.unlock();
}

int main()
{
	int time;
	std::cin >> time;
	std::string name;
	std::cin >> name;
	std::thread call(wait_for_call, time, name);
	std::thread call_skillbox(wait_for_call, 4, "Skillbox");
	call.detach();
	call_skillbox.detach();
	std::this_thread::sleep_for(std::chrono::seconds(10));
	if (call.joinable()) call.join();
	if (call_skillbox.joinable())call_skillbox.join();

	std::cout << "Missed calls:\n";
	history_access.lock();
	for (int i = 0; i < history.size(); ++i) {
		std::cout << history[i] << " ";
	}
	history_access.unlock();
}
