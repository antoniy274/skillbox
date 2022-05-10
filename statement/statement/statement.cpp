#include <iostream>
#include <fstream>

int main()
{
    std::fstream fout;
    fout.open("statement.txt");
    std::string family_name, date;
    std::string max_name, max_family_name;
    int sum = 0, salary = 0, max_salary = 0;
    char name[20];
    if (fout.is_open()) {
        while (!fout.eof()) {
            fout >> name >> family_name >> salary >> date;
            if (name[fout.gcount()] == 0) continue;
            sum += salary;
            if (salary > max_salary) {
                max_salary = salary;
                max_name = name;
                max_family_name = family_name;
            }
        }
    }
    else {
        std::cout << "ERROR. File didn't open\n";
    }
    fout.close();
    std::cout << max_name << " " << max_family_name << " " << max_salary << "\n";
}