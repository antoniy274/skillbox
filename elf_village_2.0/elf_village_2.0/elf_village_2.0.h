#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Tree;
class Branch{
public:
	Branch();
	Branch(Branch* parent);
	~Branch();
protected:
	Branch* parent = nullptr;
	std::vector<Branch*> children;
	std::string name{};

	friend Tree;
};

class Tree :  Branch {
public:
	Tree();
	void askNames();
	int findName(std::string buffer);
};

inline int randomInt(int start, int end) {
	return start + rand() % (end - start);
}