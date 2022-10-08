#pragma once

#include <iostream>
#include <string>

enum Color {
	NONE,
	RED = 31,
	BLUE = 34,
	GREEN = 32,
	YELLOW = 33
};

struct Coordinate
{
	float x = 0.00f;
	float y = 0.00f;
};

class Figure {
protected:     
	Coordinate coordinate;
	Color color = Color::NONE;
public:
	virtual void area() {};
	virtual void outerRectangle() {};
};

class Circle :public Figure {
private:
	float radius = 0.00f;
public:
	float area(float R);
	void outerRectangle(int R, Color color);
};

class Square :public Figure {
private:
	float side = 0.00f;
public:
	float area(float a);
	void outerRectangle(float a, Color color);
};

class Triangle :public Figure {
private:
	float side = 0.00f;
public:
	float area(float a);
	void outerRectangle(float a, Color color);
};

class Rectangle :public Figure {
private:
	float side_a = 0.00f;
	float side_b = 0.00f;
public:
	float area(float a, float b);
	void outerRectangle(float a, float b, Color color);
};
