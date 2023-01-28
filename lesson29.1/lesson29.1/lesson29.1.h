#pragma once

#include <vector>
#include <string>


class Talent 
{
protected:
	virtual void swimming() = 0;
	virtual void dancing() = 0;
	virtual void counting() = 0;

};

class Swimming : public Talent {
	void swimming();
};

class Dancing : public Talent {
	void dancing();
};

class Counting : public Talent {
	void counting();
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
};