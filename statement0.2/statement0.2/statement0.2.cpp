#include <iostream>
#include <string>
#include <fstream>

struct statement {
    std::string name;
    std::string surname;
    std::string date;
    int money;
};

bool correct_date(std::string str);
void save_statement(std::ofstream& file, statement& salary);
void load_statement(std::ifstream& file);

int main()
{
    statement salary;
    std::cout << "Please enter a command: add or read\n";
    std::string command;
    std::cin >> command;
    if (command == "add") {
        std::ofstream file("statement.txt", std::ios::app);
        if (!file.is_open()) {
            std::cout << "Error. File is not open";
        }
        else {
            std::cout << "Enter name, surname, date, salary in file";
            std::cout << "\nEnter 0 for quit\n";

            while (std::cin >> salary.name)
            {
                if (salary.name == "0") break;
                std::cin >> salary.surname >> salary.date >> salary.money;
                if (!correct_date(salary.date)) {
                    std::cout << "Error. Date is incorrect\n";
                    continue;
                }
                save_statement(file, salary);
            }
            file.close();
        }
    }

    else if (command == "read") {
        std::ifstream file_read;
        file_read.open("statement.txt");

        if (file_read.is_open()) {
            while (!file_read.eof()) {
                load_statement(file_read);
            }
        }
        else {
            std::cout << "ERROR. File didn't open\n";
        }
        file_read.close();
    }
    else {
        std::cerr << "Error, command not found";
    }
}

bool correct_date(std::string date)
{
    int month = std::stoi(date.substr(3, 2));
    if (month > 0 && month < 13) {
        return true;
    }
    else
        return false;
}

void save_statement(std::ofstream& file, statement& salary) {
    /*auto len_name = salary.name.length();
    auto len_surname = salary.surname.length();
    auto len_date = salary.date.length();
    file.write((char*)&len_name, sizeof(len_name));
    file.write(salary.name.c_str(), len_name);
    file.write((char*)&len_surname, sizeof(len_surname));
    file.write(salary.surname.c_str(), len_surname);
    file.write((char*)&len_date, sizeof(len_date));
    file.write(salary.date.c_str(), len_date);
    file.write((char*)&salary.money, sizeof(salary.money));*/
    file << salary.name << " " << salary.surname << " " << salary.date << " " << salary.money << "\n";
}

void load_statement(std::ifstream& file) {
    /*int len_name;
    file.read((char*)&len_name, sizeof(len_name));
    salary.name.resize(len_name);
    file.read((char*)salary.name.c_str(), len_name);
    
    int len_surname;
    file.read((char*)&len_surname, sizeof(len_surname));
    salary.surname.resize(len_surname);
    file.read((char*)salary.surname.c_str(), len_surname);
    
    int len_date;
    file.read((char*)&len_date, sizeof(len_date));
    salary.date.resize(len_date);
    file.read((char*)salary.date.c_str(), len_date);
    
    file.read((char*)&salary.money, sizeof(salary.money));*/
    
    statement salary;
    file >> salary.name >> salary.surname >> salary.date >> salary.money;
    if (salary.name.size()>0) {
        std::cout << salary.name << " " << salary.surname << " " << salary.date << " " << salary.money << "\n";
    }
}