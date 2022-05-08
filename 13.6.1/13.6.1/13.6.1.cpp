/*Пользователь вводит с клавиатуры число n, далее -- n целых чисел, которые нужно записать в вектор.

Потом пользователь вводит ещё одно значение. Нужно удалить из вектора все элементы,
которые равны данному значению, и вывести итоговое состояние вектора

Пример:

Пользователь ввёл 5, потом числа 1, 3, 3, 5, 1. И потом -- число 3. 
Необходимо, чтобы в векторе остались числа 1, 5, 1, которые надо вывести их на экран. */

#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cout << "Enter the number of vector elements\n";
    std::cin >> N;
    std::vector<int> numbers(N);

    std::cout << "Populate the array: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    int number_for_delete;
    std::cout << "What numbers to remove from the array? ";
    std::cin >> number_for_delete;

    std::vector<int> new_numbers;
    new_numbers.reserve(5);
    for (auto i = 0; i < numbers.size(); i++) {
        if (numbers[i] != number_for_delete) {
            new_numbers.push_back(numbers[i]);
        }
    }
    
    for (auto i = 0; i < new_numbers.size(); i++) {
        std::cout << new_numbers[i] << " ";
    }
}