#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream fout;
    std::string path;
    std::cout << "Enter file path: ";
    std::cin >> path;
    if (path.substr(path.size() - 4, path.size()) == ".png") {
        fout.open(path, std::ios::binary);
        if (fout.is_open()) {
            char buffer[5];
            fout.read(buffer, sizeof(buffer));
            if (buffer[0] == (char)-119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') {
                std::cout << "y";
            }
            else {
                std::cout << "n";
            }
        }
        else {
            std::cout << "File did not open\n";
        }
        fout.close();
    }
    else {
        std::cout << "The input file does not match the format png\n";
    }
}