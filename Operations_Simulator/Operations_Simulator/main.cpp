#include "Operations_Simulator.h"
#include <iostream>

using namespace std;

int main()
{
	string command;

	bool operationIsStarted = false;
	bool operationIsEnded = false;
	
	OperationsSimulator OperationBegin(0.0, 0.0);

	while (!operationIsEnded) {
		cout << "Enter a command [scalpel | hemostat | tweezers | suture]:\n";
		cin >> command;

		if (command != "scalpel" && !operationIsStarted) {
			cout << "Operation must started  with \"scalpel\" command!\n";
			continue;
		}

		if (command == "scalpel") {
			if (operationIsStarted) {
				cout << "The cut was already made\n";
				continue;
			}

			double x, y;
			std::cout << "Enter the coordinates of the beginning and end of the section\n";
			std::cin >> x >> y;
			OperationBegin(x, y);

			OperationBegin.commandScalpel(x, y);
			operationIsStarted = true;
		}
		if (command == "hemostat") {
			double x;
			std::cout << "Enter the coordinate\n";
			std::cin >> x;

			OperationBegin.commandHemostat(x);
		}
		if (command == "tweezers") {
			double x;
			std::cout << "Enter the coordinate\n";
			std::cin >> x;

			OperationBegin.commandTweezers(x);
		}
		if (command == "suture") {
			OperationsSimulator OperationEnd;
			double x, y;
			std::cout << "Enter the coordinates of the beginning and end of the section\n";
			std::cin >> x >> y;
			OperationEnd(x, y);

			if (OperationEnd.IsEqual(OperationBegin, OperationEnd)) {
				operationIsEnded = true;
			}
			else {
				std::cout << "Coordinates are not equal!\n";
			}
		}
		else {
			std::cout << "Wrong command!\n";
		}
	}
	std::cout << "Operation is finished";
}
