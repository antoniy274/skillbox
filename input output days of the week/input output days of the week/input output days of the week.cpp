#include <iostream>

using namespace std;

#define DAY(n)  ( ((n) == 1) ? "Monday" : ((n) == 2) ? "Tuesday" : ((n) == 3) ? "Wednesday" : \
( (n) == 4)  ?  "Thursday" : ((n) == 5) ?  "Friday" : ((n) == 6) ?  "Saturday" : ((n) == 7) ?  "Sunday" : "ERROR")

int main() {
    int input;

    cout << "Enter the day of the week:\n";
    cin >> input;
    cout << DAY(input);
}