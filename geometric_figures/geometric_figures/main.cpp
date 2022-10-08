// geometric_figures.cpp: определяет точку входа для приложения.
//
#include "geometric_figures.h"

using namespace std;

int main()
{
    std::string answer;
    do {
        std::cout << "Enter name shape [circle] [square] [triangle] [rectangle] or exit: ";
        std::cin >> answer;
        if (answer == "circle")
        {
            double radius;
            std::cout << "Enter radius: ";
            std::cin >> radius;
            Circle* shape = new Circle();
            shape->outerRectangle(radius, RED);
            std::cout << "Area = " << shape->area(radius);
            delete shape;
        }
        else if (answer == "square")
        {
            double side;
            std::cout << "Enter side: ";
            std::cin >> side;
            Square* shape = new Square;
            shape->outerRectangle(side, GREEN);
            std::cout << "Area = " << shape->area(side);
            delete shape;
        }
        else if (answer == "triangle")
        {
            double side;
            std::cout << "Enter side: ";
            std::cin >> side;
            Triangle* shape = new Triangle;
            shape->outerRectangle(side, BLUE);
            std::cout << "Area = " << shape->area(side);
            delete shape;

        }
        else if (answer == "rectangle")
        {
            double sideA, sideB;
            std::cout << "Enter side A and side B: ";
            std::cin >> sideA >> sideB;
            Rectangle* shape = new Rectangle;
            shape->outerRectangle(sideA, sideB, YELLOW);
            std::cout << "Area = " << shape->area(sideA, sideB);
            delete shape;

        }
        else if (answer != "exit")
        {
            std::cout << "the command was not found" << std::endl;
        }

    } while (answer != "exit");
    return 0;
}