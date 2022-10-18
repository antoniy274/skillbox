#include "simulator_company.h"
#include <iostream>
#include <vector>


int main()
{
    Boss boss;
    std::cout << "Enter number of teams: ";
    int sizeTeams;
    std::cin >> sizeTeams;
    auto col = boss.addManager(sizeTeams);

    for (auto i = 0; i < col; ++i)
    {
        std::cout << "Enter number of employee for teams # " << i << ":";
        int sizeEmployee;
        std::cin >> sizeEmployee;
        for (int j = 0; j < sizeEmployee; ++j)
        {
            auto empl = boss.addAnEmployeeToAManager(i);
            empl->setName("Worker " + std::to_string(j));
        }

    }
    unsigned int awork;
    do
    {
        std::cout << "Enter Company Director's Directive: ";
        unsigned int dir;
        std::cin >> dir;
        awork = boss.setDirectorsDerective(dir);
    } while (awork != 0);


    return 0;
}