#include <iostream>
#include <fstream>
#include <string>

bool correct_date(std::string str);

int main()
{
    std::ofstream file("statement.txt", std::ios::app);
    std::string name, surname, date, salary, currency;
    std::cout << "Enter name, surname, date, salary, currency in file";
    std::cout << "\nEnter 0 for quit\n";

    while (std::cin >> name)
    {
        if (name == "0") break;
        std::cin >> surname >> date >> salary >> currency;
        file << name << " " << surname << " " << date << " " << salary << " " << currency << "\n";
    }
    file.close();
}

bool correct_date(std::string date)
{
    int month = std::stoi(date.substr(3, 2));
    if (month < 0 and month > 12) {
        return true;
    }
    else
    {
        return false;
    }
}