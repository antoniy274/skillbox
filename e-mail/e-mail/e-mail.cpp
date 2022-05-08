/*Что нужно сделать
Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.
Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @. 
Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов. 
Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. 
Точка не может быть первым или последним символом, а кроме того, две точки не могут идти подряд. 
В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:

!#$%&'*+-/=?^_`{|}~
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.*/

#include <iostream>
#include <string>
#include <cctype>

std::string checkEmail(std::string str);
int parthOneEmail(std::string str);

int main()
{
    std::cout << "Enter your e-mail addres" << '\n';
    std::string e_mail;
    std::cin >> e_mail;
    std::cout << checkEmail(e_mail);
}

int parthOneEmail(std::string str) {
    bool check = true;
    int parthOne = 0;
    int count = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '@') {
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    std::string element = "!#$%&'*+-/=?^_`{|}~";
    for (int i = 0; str[i] != '@'; ++i) {
        for (int j = 0; j < element.length(); ++j) {
            if (str[i] == element[j])
                ++parthOne;
        }
        if (isalnum(str[i])) {
            ++parthOne;
        }
        if (str[i] == '.' && str[i + 1] == '.') {
            check = false;
            break;
        }
    }
    if (str[0] == '.') {
        check = false;
    }
    if (parthOne > 64 || parthOne == 0) {
        check = false;
    }
    if (check && count == 1) {
        return parthOne;
    }
    else {
        return 0;
    }
}

std::string checkEmail(std::string str) {
    bool check = false;
    int parthTwo = parthOneEmail(str);
    if (parthTwo != 0) {
        for (int i = parthTwo; i != (str.size() - 1); ++i) {
            if (isalnum(str[i]) || str[i] == '.' || str[i] == '-') {
                check = true;
                ++parthTwo;
            }
            if (str[i] == '.' && str[i + 1] == '.') {
                check = false;
                break;
            }
        }
        if (str[str.size()] == '.') {
            check = false;
        }
        if (parthTwo > 63 || parthTwo == 0) {
            check = false;
        }
    }
    if (check) {
        return "Yes";
    }
    else {
        return ("No");
    }
}
