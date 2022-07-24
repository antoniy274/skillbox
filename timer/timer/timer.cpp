// timer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
    tm timerTime = {};

    std::cout<<"Set the time on the timer:: [MM:SS]" << std::endl;
    std::cin >> std::get_time(&timerTime, "%M:%S");
    time_t currentTime = time(nullptr);
    time_t targetTime = currentTime + timerTime.tm_min * 60 + timerTime.tm_sec;

    while (currentTime != targetTime) {
        time_t diff = targetTime - currentTime;
        currentTime = time(nullptr);
        if (currentTime + diff != targetTime) {
            int newDiff = targetTime - currentTime;
            int minutes = newDiff / 60;
            int seconds = newDiff % 60;
            std::cout << minutes << ":" << seconds / 10 << seconds % 10 << '\n';
        }
    }
    std::cout << "DING! DING! DING!";
}
