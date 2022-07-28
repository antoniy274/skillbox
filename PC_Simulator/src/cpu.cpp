#include <vector>
#include "..\include\cpu.h"
#include "..\include\ram.h"

void compute() {
    int count = 0;
    for (auto & i : read()) {
        count += i;
    }
    std::cout << count << std::endl;
}