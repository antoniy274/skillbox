/*Что нужно сделать:

Написать функцию, которая принимаем указатель на char, по которому лежит строка. 

Функция должна возвращать true, если вторая строка является подстрокой первой.

Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения -- bool
Функция не использует библиотек кроме <iostream> и <cstring> или другую для работы со строками
Функция корректно определяет, является ли вторая строка подстрокой первой*/

#include <iostream>
#include <cstring>

bool substr(char* f, char* s);

int main()
{
    char a[] = "Hello word";
    char b[] = "wor";
    char c[] = "war";

    if (substr (a,c)){
        std::cout << "true";
    }
    else
        std::cout << "false";

}

bool substr(char* f, char* s) {
    bool entry = false;
    for (int i = 0; *(f + i) != '\0'; ++i) {
        if (*(f + i) == (* s)) {
            for (int j = 0; *(s + j) != '\0'; ++j) {
                if (*(s + j) == *(f + i + j)) {
                    entry = true;
                }
                else {
                    entry = false;
                    break;
                }
            }
        }
    }
    return entry;
}