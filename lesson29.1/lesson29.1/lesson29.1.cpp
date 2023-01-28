#include "lesson29.1.h"
#include <iostream>

Dog::Dog(std::string m_name, int m_age)
{
	name = m_name;

	if (m_age >= 0 && m_age < 30) 
	{
		age = m_age;
	}
	else
	{
		std::cout << "Incorrect age" << "\n";
	}
}

void Dog::voice()
{
	std::cout << "Bark";
}

void Dog::setName(std::string m_name)
{
	std::cout << name;
}

void Dog::getName(std::string m_name)
{
	name = m_name;
}

void Dog::setAge(int m_age)
{
	std::cout << age;
}

void Dog::getAge(int m_age)
{
	if (m_age >= 0 && m_age < 30)
	{
		age = m_age;
	}
	else
	{
		std::cout << "Incorrect age" << "\n";
	}
}


void Dog::show_talents()
{

}

void Swimming::swimming()
{
	std::cout << "It can “Swim”" << std::endl;
}

void Dancing::dancing()
{
	std::cout << "It can “Dance”" << std::endl;
}

void Counting::counting()
{

}
