#include <iostream>

int jump(int step);

int main() {
    int a;
    std::cin >> a;
    std::cout << jump(a);
}

int jump(int step)
{
    if (step < 0)
        return 0;
    if (step == 0)
        return 1;
    return jump(step - 3) + jump(step - 2) + jump(step - 1);
}