#include <iostream>
#include "geometric_figures.h"

int main()
{
    std::string answer;
    do {
        std::cout << "Enter name shape [circle] [square] [triangle] [rectangle]: ";
        std::cin >> answer;
        if (answer == "circle")
        {
            double radius;
            std::cout << "Enter radius: ";
            std::cin >> radius;
            Circle* shape = new Circle(radius, Shape::RED, 2, 4);
            shape->area();
            delete shape;
        }
        else if (answer == "square")
        {
            double side;
            std::cout << "Enter side: ";
            std::cin >> side;
            Square* shape = new Square(side, Shape::GREEN, 15, 44);
            shape->area();
            delete shape;
        }
        else if (answer == "triangle")
        {
            double side;
            std::cout << "Enter side: ";
            std::cin >> side;
            Triangle* shape = new Triangle(side, Shape::BLUE, 9, 58);
            shape->area();
            delete shape;

        }
        else if (answer == "rectangle")
        {
            double sideA, sideB;
            std::cout << "Enter side A and side B: ";
            std::cin >> sideA >> sideB;
            Rectangle* shape = new Rectangle(sideA, sideB, Shape::YELLOW, 100, 23.3);
            delete shape;

        }
        else if (answer != "exit")
        {
            std::cout << "the command was not found" << std::endl;
        }

    } while (answer != "exit");
    return 0;
}