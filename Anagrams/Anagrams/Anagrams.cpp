#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isAnagram(string str1, string str2) {
    map<char, int> firstStr;
    map<char, int> secondStr;

    if (str1.length() != str2.length()) return false;

    for (int i = 0; i < str1.length(); i++) {
        if (firstStr.find(str1[i]) != firstStr.end()) {
            firstStr[str1[i]]++;
        }
        else {
            firstStr.insert(make_pair(str1[i], 1));
        }
    }

    for (int i = 0; i < str2.length(); i++) {
        if (secondStr.find(str2[i]) != secondStr.end()) {
            secondStr[str2[i]]++;
        }
        else {
            secondStr.insert(make_pair(str2[i], 1));
        }
    }
    if (firstStr == secondStr) return true;
    else return false;

}

int main() {
    string str1;
    string str2;

    cout << "Enter two words\n";
    cin >> str1 >> str2;

    cout << isAnagram(str1, str2);
}