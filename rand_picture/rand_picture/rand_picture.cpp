#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::srand(std::time(nullptr));
    int height = 0, width = 0;
    std::cout << "Enter height and width for picture:\n";
    std::cin >> height >> width;

    std::ofstream file("pic.txt");
    file.clear();
    
    std::vector <int> picture[1][1];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int a = std::rand() % 2;
            file << a;
        }
        file << "\n";
    }
    file.close();
}