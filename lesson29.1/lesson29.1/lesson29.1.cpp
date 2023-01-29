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
	for (int i = 0; i < talent.size(); ++i) {
		talent[i].print_talent();
	}
}

void Dog::get_talents(std::string m_talent)
{
	Dancing dance;
	Swimming swimming;
	Counting counting;
	if (m_talent == "dance") {
		talent.push_back(dance);
	}
	else if (m_talent == "swim") {
		talent.push_back(swimming);
	}
	else if (m_talent == "count") {
		talent.push_back(counting);
	}
	else
		std::cout << "Invalid talant";
}

void Swimming::print_talent()
{
	std::cout << "It can “Swim”" << std::endl;
}

void Dancing::print_talent()
{
	std::cout << "It can “Dance”" << std::endl;
}

void Counting::print_talent()
{
	std::cout << "It can “Count”" << std::endl;
}
