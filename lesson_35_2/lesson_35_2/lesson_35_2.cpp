#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>

int main()
{
    std::vector<int> vec = { 1, 2, 3, 3, 4, 4, 1, 19, 23, 19 };

    auto set = [](const std::vector<int>& vec)
    {
        std::unordered_set<int> u_set(vec.begin(), vec.end());
        return std::make_unique<std::vector<int>>(u_set.begin(), u_set.end());
    };

    auto ptr = set(vec);

    for (const auto& s : *ptr.get())
        std::cout << s << " ";
    std::cout << std::endl;


}