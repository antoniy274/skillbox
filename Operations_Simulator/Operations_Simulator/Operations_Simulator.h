#pragma once
#include <iostream>

class OperationsSimulator {
private:
	double x;
	double y;

public:
	OperationsSimulator(double begin, double end);
	OperationsSimulator() {};
	~OperationsSimulator();
	void commandScalpel(double begin, double end);
	void commandHemostat(double coordinate);
	void commandTweezers(double coordinate);
	void commandSuture(double begin, double end);
	bool IsEqual(OperationsSimulator first, OperationsSimulator second);
}; 