#include <iostream>

int main()
{
    int array[] = { 1, 2, 3, 4, 5 }; // список инициализаторов
    for (auto i : array)
        std::cout << i << ' ';
}