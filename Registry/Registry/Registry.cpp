#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> patients;
    string input;
    int i = 0;
    while (getline(cin, input)) {
        if (input == "Next") {
            auto item = patients.begin();
            if (item != patients.end()) {
                cout << item->first << endl;
                if (--item->second == 0) patients.erase(patients.begin());
            }
            else
                std::cout << "Error" << " Map is null\n";
        }
        else {
            if (patients.find(input) == patients.end()) patients.insert(make_pair(input, 1));
            else patients[input]++;
        }
        i++;
    }
}