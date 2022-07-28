#include <iostream>
#include <fstream>
#include <vector>
#include "..\include\disk.h"
#include "..\include\ram.h"

void save() {
    std::ofstream disk("data.txt");
    if (disk.is_open()) {
        for (int i = 0; i < read().size(); i++) {
            disk.write((char *)& read()[i], sizeof(read()[i]));
        }
        disk.close();
    }
}
void load() {
    std::ifstream disk("data.txt");
    std::vector<int> buffer(8);
    if (disk.is_open()) {
        for (auto & i: buffer) {
            disk.read((char *)& i, sizeof(i));
        }
        disk.close();
        write(buffer);
    }
}

