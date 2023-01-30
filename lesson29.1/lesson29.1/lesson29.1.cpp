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

Dog::~Dog()
{
	for (int i = 0; i < talents.size(); ++i) {
		delete talents[i];
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
	for (int i = 0; i < talents.size(); ++i) {
		talents[i]->print_talent();
	}
}

void Dog::add_talent(Talent* talent)
{
	talents.push_back(talent);
}

void Swimming::print_talent()
{
	std::cout << "It can Swim" << std::endl;
}

void Dancing::print_talent()
{
	std::cout << "It can Dance" << std::endl;
}

void Counting::print_talent()
{
	std::cout << "It can Count" << std::endl;
}
