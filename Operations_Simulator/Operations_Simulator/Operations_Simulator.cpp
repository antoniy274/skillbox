#include "Operations_Simulator.h"
#include <iostream>

// Вроде конструктор
OperationsSimulator(double begin, double end) {
	x = begin;
	y = end;
}

// Функции класса
void commandScalpel(double begin, double end) {
	std::cout << "The incision was made between " << begin << " and " << end << '\n';
}
void commandHemostat(double coordinate) {
	std::cout << "Hemostat applied\n";
}
void commandTweezers(double coordinate) {
	std::cout << "Tweezers applied\n";
}
void commandSuture(double begin, double end) {
	std::cout << "The wound is sutured\n";
}

bool IsEqual(OperationsSimulator first, OperationsSimulator second) {
	return first.x == second.x && first.y == second.y;
}
