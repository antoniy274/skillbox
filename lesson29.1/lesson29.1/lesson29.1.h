#pragma once

#include <vector>
#include <string>


class Talent 
{
public:
	virtual void print_talent() = 0;
};

class Swimming : public Talent {
	void print_talent();
};

class Dancing : public Talent {
	void print_talent();
};

class Counting : public Talent {
	void print_talent();
};

class Dog: public Swimming, Dancing, Counting
{
private:
	std::string name;
	int age;
	std::vector<Talent> talent;
public:
	Dog() {};
	Dog(std::string m_name, int m_age = 0);
	void voice();
	void setName(std::string m_name);
	void getName(std::string m_name);
	void setAge(int m_age);
	void getAge(int m_age);
	
	void show_talents();
	void get_talents(std::string m_talent);
};