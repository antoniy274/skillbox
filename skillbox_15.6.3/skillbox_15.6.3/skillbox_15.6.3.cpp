

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect;
    int temp;
    int num;
    std::cin >> num;
    if (num != -1 && num != -2) {
        vect.push_back(num);
    }
    while (num != -2) {
        // Сортировка массива пузырьком
        for (auto i = 0; i < vect.size() - 1; i++) {
            for (auto j = 0; j < vect.size() - i - 1; j++) {
                if (vect[j] > vect[j + 1]) {
                    // меняем элементы местами
                    temp = vect[j];
                    vect[j] = vect[j + 1];
                    vect[j + 1] = temp;
                }
            }
        }
        // Ввывод пятого элемента для уникальных элементов
        // Реализовал случайно
        /*if (num == -1) {
            int count = 5;
            for (auto i = 0; i < vect.size() - 1; ++i) {
                if (vect[i] == vect[i + 1]) {
                    continue;
                }
                if (vect[i] != vect[i + 1]) {
                    count--;
                }
                if (count == 0) {
                    std::cout << vect[i];
                }
            }
        }*/

        // Вывод пятого элемента
        if (num == -1) {
            if (vect.size() >= 4) {
                std::cout << vect[4];
            }
            else {
                std::cout << "Error... Size is not equal to five";
            }
        }

        std::cin >> num;
        if (num != -1 && num != -2) {
            vect.push_back(num);
        }
    }
}