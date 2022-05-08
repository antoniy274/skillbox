#include <iostream>

int main()
{
	//Инициализация массива
	double numbers[15];
	for (int i = 0; i < 15; ++i) {
		std::cout << "Enter number: ";
		std::cin >> numbers[i];
	}

	//Сортировка пузырьком
	for (int idx_i = 0; idx_i + 1 < 15; ++idx_i) {
		for (int idx_j = 0; idx_j + 1 < 15 - idx_i; ++idx_j) {
			if (numbers[idx_j + 1] < numbers[idx_j]) {
				std::swap(numbers[idx_j], numbers[idx_j + 1]);
			}
		}
	}

	//Вывод массива
	for (int i = 0; i < 15; ++i) {
		std::cout << numbers[i] << ' ';
	}
}