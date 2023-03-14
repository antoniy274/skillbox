#include "lesson29.2.h"

const double pi = 3.14;

double Circle::square()
{
	return pi * R * R;
}

BoundingBoxDimensions Circle::dimensions()
{
	BoundingBoxDimensions result;
	result.height = 2 * R;
	result.width = 2 * R;
	return result;
}

std::string Circle::type()
{
	return "Circle";
}

double Rectangle::square()
{
	return Height * Width;
}

BoundingBoxDimensions Rectangle::dimensions()
{
	BoundingBoxDimensions result;
	result.width = Width;
	result.height = Height;
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
	result.height = Side;
	result.width = h;
	return result;
}

std::string Triangle::type()
{
	return "Triangle";
}