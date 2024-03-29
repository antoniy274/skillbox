﻿/*Довольно абстрактная, но интересная задача. У нас есть двумерный массив целых чисел размером 5 на 5 элементов. 
Его надо инициализировать и отобразить на экране. Особенность именно в способе этой инициализации. 
Элементы должны быть инициализированы не последовательно, а змейкой. 
Т.е. в конце каждой строки мы не должны переходить к первому элементу следующей строки, 
но начнём наоборот — с последнего элемента и так далее. 
В итоге, в конечном отображении нашего массива числа должны быть упорядочены по возрастанию 
но змеевидно от строки к строке. Сама же последовательность чисел — это простое линейное возрастание от 0 до 24, 
для её учёта можно завести отдельную переменную.

Попытайтесь решить эту задачу, используя минимальное количество временных переменных и без условных переходов if. 
Если вы найдёте эту самую формулу индексации — будет замечательно! Предупреждаю, она может быть весьма витиеватая.*/

#include <iostream>

int main()
{
    int matrix[5][5];
    int element = 1;
    
    for (auto i = 0; i < 5; ++i) {
        if (i % 2 == 0) {
            for (auto j = 0; j < 5; ++j) {
                matrix[i][j] = element;
                element++;
            }
        }
        else if(i % 2 != 0) {
            for (auto j = 4; j >= 0; --j) {
                matrix[i][j] = element;
                element++;
            }
        }
    }

    for (auto i = 0; i < 5; ++i) {
        for (auto j = 0; j < 5; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
