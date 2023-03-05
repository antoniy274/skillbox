#include "lesson29.2.h"

const double pi = 3.14;

double Circle::square(double R)
{
	return pi * R * R;
}

void Circle::dimensions(double R)
{
	double length = 2 * R;
	double width = 2 * R;
	std::cout << "length: " << length << " width: " << width << "\n";
}

void Circle::type()
{
	std::cout << "Circle";
}

void Circle::printParams(Shape* shape)
{
	shape->type();
	shape->square();
	shape->dimensions();
}

double Rectangle::square()
{
	return 0.0;
}

void Rectangle::dimensions()
{
}

std::string Rectangle::type()
{
	return std::string();
}
