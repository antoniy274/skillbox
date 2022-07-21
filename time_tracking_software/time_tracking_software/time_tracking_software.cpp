#include <iostream>
#include <ctime>
#include <map>
#include <vector>
#include <string>

struct Task {
    std::string name;
    time_t timeSpent;
};

enum Commands
{
    BEGIN = 1,
    END,
    STATUS,
    EXIT,
};

std::string getTime(time_t timeSpent) {
    int days = timeSpent / 864000;
    int hours = timeSpent / 3600 % 24;
    int minutes = (timeSpent % 3600) / 60;
    int seconds = timeSpent % 60;

    return std::to_string(days) + " days " + std::to_string((hours / 10)) + std::to_string(hours % 10)
        + ":" + std::to_string((minutes / 10)) + std::to_string(minutes % 10)
        + ":" + std::to_string((seconds / 10)) + std::to_string(seconds % 10);
}

Task closeTask(std::string& currentTaskName, time_t& t) {
    time_t timeSpent = (time_t)difftime(time(nullptr), t);
    t = 0;

    std::cout << currentTaskName << " is over. Time spent: "
        << getTime(timeSpent) << std::endl;

    std::string taskName = currentTaskName;
    currentTaskName = "";

    Task closedTask;
    closedTask.name = taskName;
    closedTask.timeSpent = timeSpent;

    return closedTask;
}

int main()
{
    std::map <std::string, int> commands;
    commands["begin"] = BEGIN;
    commands["end"] = END;
    commands["status"] = STATUS;
    commands["exit"] = EXIT;

    std::vector<Task> closedTask;
    std::string inputComand;
    std::string currentTaskName;
    time_t t = 0;

    while (true) {
        std::cout<< "Enter the command: [begin|end|status|exit]\n";
        std::cin >> inputComand;
        switch (commands[inputComand]) {
            case BEGIN:{
                if (!currentTaskName.empty()) {
                closedTask.push_back(closeTask(currentTaskName, t));
                }
                std::cout<<"Enter the name of a new task:\n";
                std::cin >> currentTaskName;
                t = time(nullptr);
            }
                break;
            case END: {
                if (!currentTaskName.empty()) {
                    closedTask.push_back(closeTask(currentTaskName, t));
                }
                break;
            }
            case STATUS: {
                if (!closedTask.empty()) {
                    std::cout << "Closed tasks:\n";
                    for (auto& i : closedTask) {
                        std::cout << "Task: " << i.name << ". Time spent: " << getTime(i.timeSpent) << "\n";
                    }
                }
                if (!currentTaskName.empty()) {
                    std::cout << "\nCurrent task is " << currentTaskName << std::endl;
                }
                break;
            }
            case EXIT:
                return 0;
            default:
                std::cout << "Wrong command!" << std::endl;
                break;
        }
    }
}
