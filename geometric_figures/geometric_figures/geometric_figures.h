#pragma once

#include <iostream>
#include <string>

enum Collor {
	RED = 1,
	BLUE,
	GREEN,
	PURPURE,
	None
};

struct Coordinate
{
	float x = 0.00f;
	float y = 0.00f;
};

class Figure {
private:     
	Coordinate coordinate;
	int collor = Collor::None;
public:
	virtual float area() {};
	virtual void outerRectangle() {};
};
