#pragma once

#include <iostream>

struct BoundingBoxDimensions
{
public:
	float length;
	float width;
}; 

class Shape {
public:
	virtual double square() = 0; //— возвращает площадь конкретной фигуры;
	virtual BoundingBoxDimensions dimensions() = 0; //— размеры описывающего прямоугольника;
	virtual std::string type() = 0; //— название конкретного типа, например, вернуть строку Triangle для класса Triangle;
	virtual void printParams(Shape* shape) = 0;
	{
		std::cout << "Type: " << shape->type() << "\n";
		std::cout << "Square: " << shape->square() << "\n";
	}
};

class Circle : public Shape {
private:
	double R;
public:
	double square(double R);
	BoundingBoxDimensions dimensions ();
	std::string type();
};

class Rectangle : public Shape {
private:
	double Length;
	double Width;
public:
	double square();
	BoundingBoxDimensions dimensions();
	std::string type();
};

//Будем считать, что треугольник равносторонний
class Triangle : public Shape {
private:
	double Side;
	double h = sqrt(3) * Side / 2;
public:
	double square();
	BoundingBoxDimensions dimensions();
	std::string type();
};
