/*После посылки из Китая осталась спец. плёнка для бережной перевозки груза — пупырка. Всего в пупырке 12 на 12 шариков-пузырьков. 
Состояние любого пузырька — это всегда либо он целый, либо нет, т.е. true или false (тип массива bool). 
Для начала, требуется реализовать отдельную функцию инициализации пупырки начальным состоянием — полностью целая пупырка, 
т.е. все элементы true. Но это только самое начало.

Программа заключается в последовательном лопанье целых регионов пузырьков. 
Перед каждым таким лопаньем надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, x — лопнутый. 
Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопанье. 
Пользователь вводит две координаты: координаты начала региона и конца прямоугольного региона. 
Сама процедура лопанья пузырей должна быть реализована с помощью отдельной функции, 
все аргументы должны проверяться на их валидность, что они в в рамках диапазона возможных значений — иначе должна быть выведена ошибка.
После лопанья каждого пузыря, который не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.

Лопанье должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа заканчивает выполнение. 
В принципе, вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки, т.к. 
она выполняется после каждого лопанья.*/

#include <iostream>

void initialization( bool arr[12][12]);
bool print_and_check_pimple(bool arr[12][12]);
void bursting (bool pimple[][12], int startX, int startY, int endX, int endY);


int main()
{
    bool matrix[12][12];
    initialization(matrix);
    int startX, startY, endX, endY;
    while (!print_and_check_pimple(matrix)) {
        std::cout << "Enter the start koordinats:";
        std::cin >> startX >> startY;
        std::cout << "Enter the koordinats below the start one:";
        std::cin >> endX >> endY;

        if (startX < 1 || startX > 12 || startY < 1 || startY > 12
            || endX < 1 || endX > 12 || endY < 1 || endY > 12) {
            std::cout << "Invalid range!\n";
        }
        else {
            bursting(matrix, --startX, --startY, --endX, --endY);
        }
    }
    std::cout << "Done!";
}

void initialization(bool arr[12][12]) {
    for (auto i = 0; i < 12; ++i) {
        for (auto j = 0; j < 12; ++j) {
            arr[i][j] = true;
        }
    }
}


bool print_and_check_pimple(bool arr[12][12]) {
    bool empty = true;
    for (auto i = 0; i < 12; ++i) {
        for (auto j = 0; j < 12; ++j) {

            if (arr[i][j]) {
                std::cout << "o ";
                empty = false;
            }
            else {
                std::cout << "x ";
            }
        }
        std::cout << "\n";
    }

    return empty;
}

void bursting (bool pimple[][12], int startX, int startY, int endX, int endY) {
    int startPointX;
    int startPointY;
    int endPointX;
    int endPointY;
    if (startX <= endX) {
        startPointX = startX;
        endPointX = endX;
    }
    else {
        startPointX = endX;
        endPointX = startX;
    }
    if (startY <= endY) {
        startPointY = startY;
        endPointY = endY;
    }
    else {
        startPointY = endY;
        endPointY = startY;
    }
    for (int i = startPointY; i <= endPointY; i++) {
        for (int j = startPointX; j <= endPointX; j++) {
            pimple[i][j] = false;
            std::cout << "Pop!\n";
        }
    }

}

