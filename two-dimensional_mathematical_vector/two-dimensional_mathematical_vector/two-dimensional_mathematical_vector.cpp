#include <iostream>

// TDMV: two - dimensional_mathematical_vector 
struct TDMV {
    double x;
    double y;
};

void add(TDMV &a, TDMV b);
void subtract(TDMV &a, TDMV b);
void  scale(TDMV &a, double b);
double length(TDMV a);
void  normalize(TDMV &a);


int main()
{
    std::cout << "Enter the command\n";
    std::string answer;
    std::cin >> answer;

    if (answer == "add") {
        std::cout << "Enter the coordinate of the first vector: ";
        TDMV a;
        std::cin >> a.x >> a.y;
        std::cout << "Enter the coordinate of the second vector: ";
        TDMV b;
        std::cin >> b.x >> b.y;
        add(a, b);
    }
    else if(answer == "subtract"){
        std::cout << "Enter the coordinate of the first vector: ";
        TDMV a;
        std::cin >> a.x >> a.y;
        std::cout << "Enter the coordinate of the second vector: ";
        TDMV b;
        std::cin >> b.x >> b.y;
        subtract(a, b);
    }
    else if (answer == "scale") {
        std::cout << "Enter the coordinate of the first vector: ";
        TDMV a;
        std::cin >> a.x >> a.y;
        std::cout << "Enter the scale: ";
        double b;
        std::cin >> b;
        scale(a, b);
    }
    else if (answer == "length") {
        std::cout << "Enter the coordinate of the vector: ";
        TDMV a;
        std::cin >> a.x >> a.y;
        std::cout << "The length of the vector is " << length(a);
    }
    else if (answer == "normalize") {
        std::cout << "Enter the coordinate of the vector: ";
        TDMV a;
        std::cin >> a.x >> a.y;
        normalize(a);
    }
    else {
        std::cout << "Wrong command";
    }
}

void add(TDMV &a, TDMV b) {
    a.x += b.x;
    a.y += b.y;
    std::cout << "The sum of a and b is " << a.x << " " << a.y;
}

void subtract(TDMV &a, TDMV b) {
    a.x -= b.x;
    a.y -= b.y;
    std::cout << "The difference between a and b is " << a.x << " " << a.y;
}

void  scale(TDMV &a, double b) {
    a.x *= b;
    a.y *= b;
    std::cout << "Multiplication of a vector by a scalar " << a.x << " " << a.y;
}

double length(TDMV a) {
    double c;
    c = sqrt(pow(a.x, 2) + pow(a.y, 2));
    return c;
}

// Для нормализации вектора достаточно вычислить его длину и разделить каждый компонент на эту длину
void  normalize(TDMV &a) {
    a.x /= length(a);
    a.y /= length(a);
    std::cout << "Vector normalization " << a.x << " " << a.y;
}