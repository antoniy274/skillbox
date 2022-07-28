#include <vector>
#include "..\include\ram.h"

std::vector<int> buffer(8);

std::vector<int> read() {
    return buffer;
}

void write(std::vector<int> newBuffer) {
    for (int i = 0; i < buffer.size(); i++) {
        buffer[i] = newBuffer[i];
    }
}


