#pragma once

#include <vector>
#include <string>


class Talent 
{
public:
	virtual void print_talent() = 0;
};

class Swimming : public Talent {
public:
	Swimming() {};
	void print_talent();
};

class Dancing : public Talent {
public:
	void print_talent();
};

class Counting : public Talent {
public:
	void print_talent();
};

class Dog
{
private:
	std::string name;
	int age;
	std::vector<Talent*> talents;
public:
	Dog() {};
	Dog(std::string m_name, int m_age = 0);
	~Dog();
	void voice();
	void setName(std::string m_name);
	void getName(std::string m_name);
	void setAge(int m_age);
	void getAge(int m_age);
	
	void show_talents();
	void add_talent(Talent* talent);
};