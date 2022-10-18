#pragma once
#include <vector>
#include <iostream>
#include <string>

class Manager;
class Employee;
class Boss
{
    int _countManager{ 0 };
    unsigned int _countAWork{ 0 };
    std::vector<Manager*> manager;

public:
    Boss(const int countManager = 0);
    ~Boss();
    int addManager(const int countManager);
    int getCountManager();
    Employee* addAnEmployeeToAManager(const int managerId);
    unsigned int setDirectorsDerective(unsigned int directive);
};


class Manager
{
public:
    enum Task
    {
        A,
        B,
        C
    };
private:
    static unsigned int id;
    unsigned int _id{ 0 };
    std::vector<Employee*> _team;
    int taskSize{ 0 };
    unsigned int availableEmployees{ 0 };
public:
    Manager();
    ~Manager();
    Employee* addEmployee();
    void addTaskSize(unsigned int directive);
    unsigned int distributionOfTask();

};


class Employee
{
    bool _work{ false };
    std::string name{ "no name" };
    Manager::Task _task;
public:

    bool isWork()
    {
        return _work;
    }
    void setTask(bool work, Manager::Task task)
    {
        _task = task;
        _work = true;
    }
    void setName(const std::string& name)
    {
        this->name = name;
    }
    void getTask(const unsigned int managerId)
    {
        std::string task;
        switch (_task)
        {
        case Manager::A:
            task = "A";
            break;
        case Manager::B:
            task = "B";
            break;
        case Manager::C:
            task = "C";
            break;
        default:
            break;
        }
        std::cout << "Group " << managerId << ": " << name << " execute task " << task << std::endl;
    }
};