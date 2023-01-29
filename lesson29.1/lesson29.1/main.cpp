#include "lesson29.1.h"
#include <iostream>

int main()
{
	Dog sharik("Sharik", 7);
	int count;
	std::cout << "Enter the number of abilities, if there are three at most";
	std::cin >> count;

	for (int i = 0; i < count; ++i) {
		std::string text;
		std::cout << "Enter the name of the ability from the list: swim, dance, count";
		std::cin >> text;
		sharik.get_talents(text);
	}

	sharik.show_talents();
}
