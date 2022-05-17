#include <ctime>
#include <iostream>
#include <fstream>

int main()
{
    std::srand(std::time(nullptr));
    int height = 0, width = 0;
    std::cout << "Enter height and width for picture:\n";
    std::cin >> height >> width;

    std::ofstream file("pic.txt");
    file.clear();
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file << std::rand() % 2;
        }
        file << "\n";
    }
    file.close();
}