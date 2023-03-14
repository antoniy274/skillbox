#pragma once

#include <iostream>

struct BoundingBoxDimensions
{
	double width;
	double height;
}; 

class Shape {
public:
	virtual double square() = 0; //— возвращает площадь конкретной фигуры;
	virtual BoundingBoxDimensions dimensions() = 0; //— размеры описывающего прямоугольника;
	virtual std::string type() = 0; //— название конкретного типа, например, вернуть строку Triangle для класса Triangle;
	virtual void printParams(Shape* shape)
	{
		std::cout << "Type: " << shape->type() << "\n";

	}
};

class Circle : public Shape {
private:
	double R;
public:
	Circle(double r) { R = r; }
	virtual double square();
	virtual BoundingBoxDimensions dimensions ();
	virtual std::string type();
};

class Rectangle : public Shape {
private:
	double Height;
	double Width;
public:
	Rectangle(double h, double w) { Height = h; Width = w; }
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
	Triangle(double s) { Side = s; }
	double square();
	BoundingBoxDimensions dimensions();
	std::string type();
};
