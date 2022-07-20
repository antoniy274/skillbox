#include <iostream>
using namespace std;

#define WAGONS(type, info) type ## _ ## info

#define INPUT { \
    for (int i = 0; i < 10; i++) { \
        cout << "Enter the number fo passengers in " << i + 1\
        << " wagon" << endl;       \
        cin >> wagons[i];\
    } \
};

#define ANALYZE { \
    for (int i = 0; i < 10; i++) { \
        count += wagons[i]; \
        if (wagons[i] == 0) cout << i + 1 << " wagon is empty\n"; \
        else if (wagons[i] > 20) cout << i + 1 << " wagon is crowded\n"; \
    } \
};

void wagons_analyze(int* wagons) {
    int count = 0;
    ANALYZE
        cout << "Total passengers in wagons: " << count;
}

int main() {
    int wagons[10];

    INPUT

        WAGONS(wagons, analyze)(wagons);
}