/*Задача 1

Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве, что 
сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

Пример:

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: 
{4,-1,2,1}, сумма = 6. Необходимо вывести 3 и 6*/

#include <iostream>
#include <vector>



int main() {
    std::vector<int> vect = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int maxSum = vect[0];
    int sum = vect[0];
    int lt = 0;
    int rt = lt + 1;
    int i = 0;
    int ind_i, ind_j;


    while (i != vect.size()) {
        sum += vect[rt];
        if (sum > maxSum) {
            maxSum = sum;
            ind_i = lt;
            ind_j = rt;
            rt ++;
        }
        else {
            lt++;
            rt = lt + 1;
            sum = vect[lt];
        }
        ++i;
    }
    std::cout << ind_i << " " << ind_j;
}