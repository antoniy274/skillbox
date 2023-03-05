#pragma once

#include <iostream>

class Shape {
public:
	virtual double square() = 0; //— возвращает площадь конкретной фигуры;
	virtual double dimensions() = 0; //— размеры описывающего прямоугольника;
	virtual void type() = 0; //— название конкретного типа, например, вернуть строку Triangle для класса Triangle;
	virtual void printParams(Shape* shape) = 0; //— сюда можно будет передавать любые фигуры
};

class Circle : public Shape {
private:
	double R;
public:
	double square(double R);
	void dimensions(double R);
	void type();
	void printParams(Shape* shape);
};

class Rectangle : public Shape {
private:
	double Length;
	double Width;
public:
	double square();
	void dimensions();
	std::string type();
	void printParams(Shape* shape);
};

class Triangle : public Shape {
private:
	double Side;
public:
	double square();
	void dimensions();
	std::string type();
	void printParams(Shape* shape);
};
