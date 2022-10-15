#pragma once

class Shape
{
public:
    enum Color
    {
        NONE,
        RED = 31,
        BLUE = 34,
        GREEN = 32,
        YELLOW = 33
    };

protected:
    double _coordinatesX{ 0 };
    double _coordinatesY{ 0 };
    Color _color{ Shape::NONE };

public:
    Shape(double x = 0, double y = 0, Color color = Shape::NONE)
        : _coordinatesX(x), _coordinatesY(y), _color(color)
    {
    }
    void area();
    void rectangleDraw(double a = 0, double b = 0, Color color = Shape::NONE);
};

class Circle : public Shape
{
    const double PI = 3.14;
    double _radius{ 0 };

public:
    Circle(double radius = 0, Color color = Shape::NONE, double x = 0, double y = 0)
        : _radius(radius), Shape(x, y, color)
    {
    }
    double area();
};

class Square : public Shape
{
protected:
    double _side{ 0 };

public:
    Square(double side = 0, Color color = Shape::NONE, double x = 0, double y = 0)
        : _side(side), Shape(x, y, color)
    {
    }
    double area();
};

class Triangle : public Square
{

public:
    Triangle(double side = 0, Color color = Shape::NONE, double x = 0, double y = 0)
        : Square(side, color, x, y)
    {
    }
    double area();
};

class Rectangle : public Shape
{
    double _sideA{ 0 };
    double _sideB{ 0 };

public:
    Rectangle(double sideA = 0, double sideB = 0, Color color = Shape::NONE, double x = 0, double y = 0)
        : _sideA(sideA), _sideB(sideB), Shape(x, y, color)
    {
    }
    double area();

};