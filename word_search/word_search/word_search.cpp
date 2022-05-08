#include <fstream>
#include <iostream>

int main()
{
    int count = 0;
    std::string word;
    std::cout << "Enter word for find: ";
    std::cin >> word;
    
    std::ifstream fout;
    fout.open("words.txt");
    if (fout.is_open()) {
        while (!fout.eof()) {
            std::string b_word;
            fout >> b_word;
            if (word == b_word) {
                count++;
            }
        }
    }
    else {
        std::cout << "Error. File did non open";
    }
    fout.close();
    std::cout << count;
}