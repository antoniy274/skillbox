﻿/*Задание 4. Механическое пианино

Что нужно сделать

Создайте упрощённую модель механического пианино. Всего у данного пианино семь клавиш, которые соответствуют семи нотам. 
Каждая клавиша кодируется уникальной битовой маской, которая записывается в enum. В начале программы пользователь вводит мелодию. 
Ввод осуществляется с помощью цифр на клавиатуре, от 1 до 7 включительно (от ноты до до ноты си). 
В результате из чисел может быть составлена любая комбинация нот. К примеру 512 или 154. После ввода комбинации вводится следующая. 
Всего таких комбинаций нот — 12. Как только все комбинации были введены пользователем, мелодия проигрывается. 
Для этого каждая комбинация нот последовательно выводится на экран. 
Однако на этот раз она печатается «красиво», то есть все ноты указываются словами, а не цифрами. 
При этом слова разделяются пробелами.



Рекомендации

Для вычленения отдельных символов-цифр из строки с нотами используйте оператор индексации строки. 
Для дальнейшей конвертации символа в строку используйте соответствующий конструктор.

Для простоты, чтобы из индекса ноты получить саму ноту-флаг из enum, используйте оператор сдвига. 
Общая формула такова: 1 << индекс ноты (начинается с нуля). 
К примеру, 1 << 0 — битовый флаг ноты до, 1 << 6 — битовая маска ноты си.*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

enum notes {
    C = 1,
    D = 2,
    E = 4,
    F = 8,
    G = 16,
    A = 32,
    B = 64
};

int main() {
    string notesCombinations[12];
    stringstream song;
    for (int i = 0; i < 12; ++i) {
        cin >> notesCombinations[i];
        for (int j = 0; j < notesCombinations[i].length(); ++j) {
            int n = notesCombinations[i][j] - '0';
            switch (1 << n) {
            case C:
                song << "C ";
                break;
            case D:
                song << "D ";
                break;
            case E:
                song << "E ";
                break;
            case F:
                song << "F ";
                break;
            case G:
                song << "G ";
                break;
            case A:
                song << "A ";
                break;
            case B:
                song << "B ";
                break;
            }
        }
        song << " ";
    }
    std::cout << song.str();
}