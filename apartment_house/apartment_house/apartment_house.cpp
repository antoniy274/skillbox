/*Что нужно сделать
На вход программе поступают десять фамилий в формате строк. Это фамилии жильцов квартир с первой по десятую.
Необходимо прочитать эти фамилии и записать в одномерный массив. Далее пользователь вводит три номера квартир.
Необходимо вывести в консоль фамилию жильца, проживающего в этой квартире. 
Если пользователь введёт некорректный номер квартиры, необходимо сообщить ему об этом.
*/

#include <iostream>
#include <string>

int main()
{
    const int count = 10;
    std::string family[count];
    std::cout << "Enter the names of the residents";

    for (int i = 0; i < count; ++i) {
        std::cin >> family[i];
    }

    for (int i = 0; i < 3; ++i) {
        int number;
        std::cout << "Введите номер квартиры";
        std::cin >> number;

        if (number > 10 || number < 1) {
            std::cout << "Error. Incorrect number!\n";
            break;
        }
        else {
            std::cout << family[number - 1] << "\n";
        }
    }
}