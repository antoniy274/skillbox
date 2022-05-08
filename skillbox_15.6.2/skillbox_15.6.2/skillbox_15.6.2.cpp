#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr{2, 7, 11, 15};
    int result = 9;
    for (auto i = 0; i < arr.size(); ++i) {
        for (auto j = arr.size() - 1; j > i; --j) {
            if ((arr[i] + arr[j]) == result) {
                std::cout << i << " " << j;
            }
        }
    }
}