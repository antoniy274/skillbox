#include "lesson29.2.h"

const double pi = 3.14;

double Circle::square(double R)
{
	return pi * R * R;
}

BoundingBoxDimensions Circle::dimensions()
{
	BoundingBoxDimensions result;
	result.length = 2 * R;
	result.width = 2 * R;
	return result;
}

std::string Circle::type()
{
	return "Circle";
}


double Rectangle::square()
{
	return Length * Width;
}

BoundingBoxDimensions Rectangle::dimensions()
{
	BoundingBoxDimensions result;
	result.length = Length;
	result.width = Width;
	return result;
}

std::string Rectangle::type()
{
	return "Rectangle";
}

double Triangle::square()
{
	return (Side * h) / 2;
}

BoundingBoxDimensions Triangle::dimensions()
{
	BoundingBoxDimensions result;
	result.length = Side;
	result.width = h;
	return result;
}

std::string Triangle::type()
{
	return "Triangle";
}
