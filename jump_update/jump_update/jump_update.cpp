#include <iostream>

int jump_update(int n, int k = 3);

int main()
{
    int k, n;
    std::cin >> k >> n;
    std::cout << jump_update(n, k);
}

int jump_update(int n, int k){
    if (n < 0)
        return 0;
    if (n == 0 )
        return 1;
    int sum = 0;
    for (int i = k; i > 0; --i) {
        sum += jump_update(n - i, k);
    }
    return sum;
}