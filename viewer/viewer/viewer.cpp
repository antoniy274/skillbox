#include <fstream>
#include <iostream>

int main()
{
    std::string way;
    std::cout << "Enter way to file: ";
    std::cin >> way;

    std::ifstream fout;
    fout.open("way", std::ios::binary);
    //fout.open("words.txt");
    
    if (fout.is_open()) {
        while (!fout.eof()) {
            char buffer[50];
            fout.read(buffer, sizeof(buffer) - 1);
            buffer[fout.gcount()] = 0;
            std::cout << buffer;
        }
    }
    else {
        std::cout << "File did not open\n";
    }

    fout.close();
}
