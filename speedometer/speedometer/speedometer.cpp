/*Реализуйте цифровой спидометр автомобиля. Сама модель автомобиля, которую нужно будет воссоздать, весьма проста. 
Начальная скорость — 0 км/ч. Пользователь вводит в стандартный ввод разницу (дельту) в скорости, 
и результирующая скорость показывается на спидометре в стандартный вывод. 
Так происходит до той поры, пока машина снова не остановится, то есть пока скорость не станет меньше или равна нулю 
(сравнение должно происходить с дельтой в 0,01). Диапазон возможных значений скорости машины от 0 до 150 км/ч. 
Сам показатель спидометра вместе с единицами измерения требуется записывать в отдельную строку-буфер, которая потом 
и будет показываться на экране. Точность отображения скорости — до 0,1 км/ч.

Рекомендации

Используйте цикл do … while для организации постоянного опроса пользователя. 
Для отображения числа с нужной точностью воспользуйтесь функцией std::sprintf(speed_str, "%.1f", speed_value); 
где speed_str — строка, в которую функция sprintf «печатает» значение скорости (speed_value) 
с одним знаком после десятичной точки (%.1f). */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>

int main()
{
    double speed, speed_value = 0, speed_buff = 0;
    std::cout << "Enter speed\n";
    std::cin >> speed;
    do {
        float delta = 0.01;
        char speed_str[6];
        if (speed > delta or speed < delta) {
            speed_buff += speed;
            if (speed_buff <= 150) {
                speed_value += speed;
            }
            else {
                std::cout << "Repeat input ";
                speed_buff = speed_value;
            }
        }
        if (speed_value <= 0) {
            break;
        }
        std::sprintf(speed_str, "%.1f", speed_value);
        std::cout << speed_str << "\n";
        std::cout << "Enter speed\n";
    } while (std::cin >> speed);
    std::cout << " Your car is stopped\n";
}
