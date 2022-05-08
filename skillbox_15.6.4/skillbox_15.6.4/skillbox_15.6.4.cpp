#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    std::vector<int> vect{ -100,-50, -5, 1, 10, 15 };
    int temp = 0;
    // Сортировка массива пузырьком
    for (auto i = 0; i < vect.size() - 1; i++) {
        for (auto j = 0; j < vect.size() - i - 1; j++) {
            if (abs(vect[j]) > abs(vect[j + 1])) {
                // меняем элементы местами
                temp = vect[j];
                vect[j] = vect[j + 1];
                vect[j + 1] = temp;
            }
        }
    }

    for (auto i = 0; i < vect.size(); ++i) {
        std::cout << vect[i] << " ";
    }
}
