#include "elf_village_2.0.h"
#include <iostream>


int main()
{
	Tree tree[1];

	for (int i = 0; i < 1; ++i) {
		tree[i].askNames();
	}

	int count = 0;
	std::cout << "Enter a name to search for neighbors:";
	std::string name;
	std::cin >> name;
	for (int i = 0; i < 1; ++i) {
		count = tree[i].findName(name);
		std::cout << count;
	}
}
