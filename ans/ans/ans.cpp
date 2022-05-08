#include <iostream>

void evendigits(long long n, int& ans);

int main()
{
    int ans = 0;

    evendigits(9223372036854775806, ans);

    std::cout << ans;
}

void evendigits(long long n, int& ans) {
    if (n == 0 && ans != 0) {
        return ;
    }
    else if ((n % 10) % 2 == 0) {
        ++ans;
    }
    n /= 10;
    evendigits(n, ans);
}