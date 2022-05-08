/*Требуется реализовать небольшую программу для сравнения двух двумерных матриц размерами 4х4 на предмет их полного равенства. 
Программа принимает на вход две целочисленные матрицы A и B, 
которые вводятся с помощью std::cin и сравнивает их на предмет полного равенства. 
Если матрицы равны, то об этом сообщается в стандартном выводе. 
Алгоритм должен быть по возможности оптимальным и не проводить лишних операций.*/

#include <iostream>

bool matrix_equality(int arr1[4][4], int arr2[4][4]);

int main()
{
    int matrix_first[4][4];
    int matrix_second[4][4];
    int element;

    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
            std::cout << "Enter element with coordinates for first matrix: " << i + 1 << " " << j + 1 << " ";
            std::cin >> element;
            matrix_first[i][j] = element;
        }
    }

    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
            std::cout << "Enter element with coordinates for second matrix: " << i + 1 << " " << j + 1 << " ";
            std::cin >> element;
            matrix_second[i][j] = element;
        }
    }

    if (matrix_equality(matrix_first, matrix_second)) {
        std::cout << "equal";
    }
    else {
        std::cout << "not equal";
    }

}

bool matrix_equality(int arr1[4][4], int arr2[4][4]) {
    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
            if (arr1[i][j] != arr2[i][j])
                return false;
        }
    }
    return true;
}
