#include <iostream>
#include <vector>
#include "..\include\ram.h"

void display() {
    for (auto & i : read()) {
        std::cout << i << std::endl;
    }
}