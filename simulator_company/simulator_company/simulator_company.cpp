#include "simulator_company.h"
#include <cstdlib>
#include <iostream>


Boss::Boss(const int countManager) : _countManager(countManager)
{

}
int Boss::getCountManager()
{
    return _countManager;
}

int Boss::addManager(const int countManager)
{
    if (countManager <= 0)
        return  _countManager = 0;
    _countManager = countManager;

    for (int i = 0; i < _countManager; ++i)
    {
        Manager* man = new Manager;
        manager.push_back(man);
    }
    return _countManager = manager.size();
}

Boss::~Boss()
{
    for (auto man : manager)
        delete man;
}

Employee* Boss::addAnEmployeeToAManager(const int managerId)
{
    return manager[managerId]->addEmployee();
}

unsigned int Boss::setDirectorsDerective(unsigned int directive)
{
    _countAWork = 0;
    for (auto work : manager)
    {
        work->addTaskSize(directive);
        _countAWork += work->distributionOfTask();
    }
    return _countAWork;
}


unsigned int Manager::id{ 1 };

Manager::Manager()
{
    _id = id++;
}

Employee* Manager::addEmployee()
{
    Employee* emp = new Employee;
    _team.push_back(emp);
    return emp;
}

Manager::~Manager()
{
    for (auto& emp : _team)
        delete emp;
}

void Manager::addTaskSize(unsigned int derective)
{
    std::srand(_id + derective);
    taskSize = std::rand() % _team.size() + 1;
}

unsigned int Manager::distributionOfTask()
{
    if (availableEmployees >= _team.size())
    {
        std::cout << "In group number " << _id << ", all employees are employed" << std::endl;
        return 0;
    }

    for (int i = 0, j = 0; i < taskSize && j < _team.size(); ++j)
    {
        if (!_team[j]->isWork())
        {
            _team[j]->setTask(true, static_cast<Manager::Task>(std::rand() % 3));
            ++availableEmployees;
            ++i;
            _team[j]->getTask(_id);
        }
    }
    return availableEmployees;
}