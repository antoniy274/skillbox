/*Задание 2. Сшиватель дробных чисел
Что нужно сделать

Напишите небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь, 
составьте новое число с плавающей точкой (типа double) и выведите это число обратно в консоль для проверки. 
Целая часть — это часть числа, которая находится до точки (запятой), дробная — после.

Рекомендации

Вам потребуется функция StringToDouble — std::stod. Она принимает на вход строку, содержащую в себе число.*/
#include <iostream>
#include <string>


int main()
{
    double find_number;
    std::string number;
    std::string exponenta;
    std::cout << "Enter the whole part of the number: ";
    std::cin >> number;
    std::cout << "Enter the fractional part of the number: ";
    std:: cin >> exponenta;
    number = number + '.' + exponenta;
    find_number = std::stof(number);
    std::cout << find_number;
}