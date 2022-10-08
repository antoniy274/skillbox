#include <cmath>
#include "geometric_figures.h"

float Circle::area(float R) {
	// Пытался найти переменную M_PI, но не смог
	return (3.14 * pow(R, 2));
}

void Circle::outerRectangle(int R, Color color) {
    std::string colors = std::to_string(static_cast<int> (color) + 10);
    R += 2;
    int R2 = R * 2;
    //  std::string colors = std::to_string(static_cast<int> (color) + 10);
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < R2; ++j)
        {
            if ((i == 0 && j >= 0) || (i == R - 1 && j >= 0))
            {
                std::cout << "-";
            }
            else if (j == 0 || j == R2 - 1)
            {
                std::cout << "|";
            }
            else {
                std::cout << "\x1b[" + colors + "m \x1b[0m";
            }
        }
        std::cout << std::endl;
    }
}

float Square::area(float side) {
    float S = pow(side, 2);
    return S;
}

void Square::outerRectangle(float Side, Color color) {
    float side = Side + 2;
    float side_two = side * 2;
    std::string colors = std::to_string(static_cast<int> (color) + 10);
    for (int i = 0; i < side; ++i)
    {
        for (int j = 0; j < side_two; ++j)
        {
            if ((i == 0 && j >= 0) || (i == side - 1 && j >= 0))
            {
                std::cout << "-";
            }
            else if (j == 0 || j == side_two - 1)
            {
                std::cout << "|";
            }
            else {
                std::cout << "\x1b[" + colors + "m \x1b[0m";
            }
        }
        std::cout << std::endl;
    }
}

float Triangle::area(float length) {
    return length * length * std::sqrt(3) / 4;
}

void Triangle::outerRectangle(float side, Color color) {
    side += 2;
    float side2 = side * 2;
    std::string colors = std::to_string(static_cast<int> (color) + 10);
    for (int i = 0; i < side; ++i)
    {
        for (int j = 0; j < side2; ++j)
        {
            if ((i == 0 && j >= 0) || (i == side - 1 && j >= 0))
            {
                std::cout << "-";
            }
            else if (j == 0 || j == side2 - 1)
            {
                std::cout << "|";
            }
            else {
                std::cout << "\x1b[" + colors + "m \x1b[0m";
            }
        }
        std::cout << std::endl;
    }
}

float Rectangle::area(float a, float b) {
    return a * b;
}

void Rectangle::outerRectangle(float side, float side2, Color color) {
    side = side + 2;
    side2 = side * 2;
    std::string colors = std::to_string(static_cast<int> (color) + 10);
    for (int i = 0; i < side; ++i)
    {
        for (int j = 0; j < side2; ++j)
        {
            if ((i == 0 && j >= 0) || (i == side - 1 && j >= 0))
            {
                std::cout << "-";
            }
            else if (j == 0 || j == side2 - 1)
            {
                std::cout << "|";
            }
            else {
                std::cout << "\x1b[" + colors + "m \x1b[0m";
            }
        }
        std::cout << std::endl;
    }
}