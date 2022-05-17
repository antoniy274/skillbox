#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file_read;
    std::ofstream file_write;

    file_read.open("fish.txt");
    file_write.open("basket.txt", std::ios::app);
    std::string fish;

    if (!file_read.is_open()) {
        std::cout << "File fish is not open";
    }
    else {
        std::cout << "Enter type fish or 0 for quit: ";
        while (std::cin >> fish )
        {
            if (fish == "0") break;
            int count = 0;
            while (!file_read.eof())
            {
                std::string type_fish;
                file_read >> type_fish;
                if (type_fish == fish) {
                    file_write << fish << "\n";

                    count++;
                }
            }
            std::cout << "Number of fish caught: " << count << "\n";
        }
    }
    file_read.close();
    file_write.close();
}