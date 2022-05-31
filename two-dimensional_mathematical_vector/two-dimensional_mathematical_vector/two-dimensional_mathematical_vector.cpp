#include <iostream>

// TDMV: two - dimensional_mathematical_vector 
struct TDMV {
    double x;
    double y;
};

TDMV add(TDMV a, TDMV b);
TDMV subtract(TDMV a, TDMV b);
TDMV  scale(TDMV a, double b);
double length(TDMV a);
TDMV  normalize(TDMV a);


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
        TDMV result = add(a, b);
        std::cout << "The sum of a and b is " << result.x << " " << result.y;
    }
    else if(answer == "subtract"){
        std::cout << "Enter the coordinate of the first vector: ";
        TDMV a;
        std::cin >> a.x >> a.y;
        std::cout << "Enter the coordinate of the second vector: ";
        TDMV b;
        std::cin >> b.x >> b.y;
        TDMV result = subtract(a, b);
        std::cout << "The difference between a and b is " << result.x << " " << result.y;
    }
    else if (answer == "scale") {
        std::cout << "Enter the coordinate of the first vector: ";
        TDMV a;
        std::cin >> a.x >> a.y;
        std::cout << "Enter the scale: ";
        double b;
        std::cin >> b;
        TDMV result = scale(a, b);
        std::cout << "Multiplication of a vector by a scalar " << result.x << " " << result.y;
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
        TDMV result = normalize(a);
        std::cout << "Vector normalization " << result.x << " " << result.y;
    }
    else {
        std::cout << "Wrong command";
    }
}

TDMV add(TDMV a, TDMV b) {
    TDMV result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

TDMV subtract(TDMV a, TDMV b) {
    TDMV result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

TDMV  scale(TDMV a, double b) {
    TDMV result;
    result.x = a.x * b;
    result.y = a.y * b;
    return result;
}

double length(TDMV a) {
    double c;
    c = sqrt(pow(a.x, 2) + pow(a.y, 2));
    return c;
}

// Для нормализации вектора достаточно вычислить его длину и разделить каждый компонент на эту длину
TDMV  normalize(TDMV a) {
    TDMV result;
    result.x = a.x / length(a);
    result.y = a.y /= length(a);
    return result;
}