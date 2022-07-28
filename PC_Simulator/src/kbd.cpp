#include <iostream>
#include <vector>
#include "..\include\kbd.h"
#include "..\include\ram.h"

void input() {
    std::vector<int> inputBuffer(8);
    for (int i = 0 ; i < 8; i++) {
        std::cout << "Enter the " << i + 1 << " number" << std::endl;
        std::cin >> inputBuffer[i];
    }
    write(inputBuffer);
}
