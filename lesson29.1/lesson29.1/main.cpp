#include "lesson29.1.h"
#include <iostream>

int main()
{
	Dog sharik("Sharik", 7);

	std::cout << "Add your dog's talent" << std::endl;

	Dancing* dance = new Dancing();

	sharik.add_talent(dance);
	sharik.show_talents();
}
