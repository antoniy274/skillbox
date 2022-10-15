#include <iostream>
#include <cmath>
#include "geometric_figures.h"
#include <string>
void Shape::area()
{
    std::cout << "Coordinate " << _coordinatesX << " : " << _coordinatesY << std::endl;
    std::cout << "Color : ";
    switch (_color)
    {
    case RED:
        std::cout << "\x1b[31mRED\x1b[0m" << std::endl;
        break;
    case BLUE:
        std::cout << "\x1b[34mBLUE\x1b[0m" << std::endl;
        break;
    case GREEN:
        std::cout << "\x1b[32mGREEN\x1b[0m" << std::endl;
        break;
    case YELLOW:
        std::cout << "\x1b[33mYELLOW\x1b[0m" << std::endl;
        break;
    default:
        std::cout << "Not set" << std::endl;
        break;
    }

}

void Shape::rectangleDraw(double a, double b, Color color)
{
    std::string colors = std::to_string(static_cast<int> (color) + 10);
    b *= 2;
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            if ((i == 0 && j >= 0) || (i == a - 1 && j >= 0))
            {
                std::cout << "-";
            }
            else if (j == 0 || j == b - 1)
            {
                std::cout << "|";
            }
            else
            {
                std::cout << "\x1b[" + colors + "m \x1b[0m";
            }

        }
        std::cout << std::endl;
    }
}

double Circle::area()
{
    Shape::area();
    double diametr = _radius * _radius;
    double p = PI * diametr;
    std::cout << "Area circle: " << p << std::endl;
    Shape::rectangleDraw(diametr, diametr, _color);
    return p;
}

double Square::area()
{
    Shape::area();
    double p = _side * _side;
    std::cout << "Area square: " << p << std::endl;
    Shape::rectangleDraw(_side, _side, _color);
    return p;
}

double Triangle::area()
{
    const double f = sqrt(3) / 4;
    Shape::area();
    double p = f * _side * _side;
    std::cout << "Area triangle: " << p << std::endl;
    Shape::rectangleDraw(_side, _side, _color);
    return p;
}

double Rectangle::area()
{
    Shape::area();
    double p = _sideA * _sideB;
    std::cout << "Area rectangle: " << p << std::endl;
    Shape::rectangleDraw(_sideA, _sideB, _color);
    return p;
}