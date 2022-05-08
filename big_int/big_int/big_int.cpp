/*Вы продолжаете писать калькулятор, работающий над вещественными числами повышенной точности.
Вы уже научились проверять корректность записи вещественных чисел в виде строк,
и теперь перед вами новая цель — научиться сравнивать такие вещественные числа.

Пользователь вводит две строки, задающие вещественные числа, в том же формате, как было описано в задаче «Длинное вещественное число».
Программа должна проверить корректность ввода (для этого можно переиспользовать код, написанный в задаче «Длинное вещественное число»),
после чего вывести слово Less, если первое число строго меньше второго; слово More, если первое число строго больше второго;
и слово Equal, если введённые числа равны.*/


//Странная ошибка
#include <iostream>
#include <string>

bool checkingNumbers(std::string bigInt);
bool has_dot(std::string bigInt);
bool has_minus(std::string bigInt);
std::string delete_null(std::string bigInt);
std::string comparisonOfNumbers(std::string bigInt, std::string bigInt2);

int main() {
	std::string bigInt1, bigInt2;
	std::cin >> bigInt1 >> bigInt2;
	std::cout << comparisonOfNumbers(bigInt1, bigInt2);
}
//Проверка наличия знака минус
bool has_minus(std::string bigInt) {
	bool check = false;
	if (bigInt[0] == '-') {
		check = true;
	}
	return check;
}

//Проверка наличия точек
bool has_dot(std::string bigInt) {
	bool check = false;
	for (int i = 0; i < bigInt.size(); ++i) {
		if (bigInt[i] == '.') {
			check = true;
		}
	}
	return check;
}

//Удаление нулей с начала числа
std::string delete_null(std::string bigInt) {

	if (bigInt[0] == '-') {
		int i = 1;
		while (bigInt[i] == '0') {
			i++;
		}
		bigInt.erase(1, i - 1);
	}
	else {
		int i = 0;
		while (bigInt[i] == '0') {
			i++;
		}
		bigInt.erase(0, i);
	}
	return bigInt;
}


//Сравнение чисел 
std::string comparisonOfNumbers(std::string bigInt, std::string bigInt2)
{
	std::string path_bigIntBeforeDot;
	std::string path_bigIntAfterDot;
	std::string path_bigInt2BeforeDot;
	std::string path_bigInt2ArterDot;
	if (checkingNumbers(bigInt) == true && checkingNumbers(bigInt2) == true) {
		//Подготовка к сравнению. Превращение целых цисел в дробные 
		if (has_dot(bigInt) == false) {
			bigInt.push_back('.');
			bigInt.push_back('0');
		}
		if (has_dot(bigInt2) == false) {
			bigInt2.push_back('.');
			bigInt2.push_back('0');
		}
		//Подготовка к сравнению. Разделение дробной и целой части. Т.к целое число частный случай дробного
		path_bigIntBeforeDot = bigInt.substr(0, bigInt.find('.'));
		path_bigIntAfterDot = bigInt.substr(bigInt.find('.') + 1, bigInt.size());
		path_bigInt2BeforeDot = bigInt2.substr(0, bigInt2.find('.'));
		path_bigInt2ArterDot = bigInt2.substr(bigInt2.find('.') + 1, bigInt2.size());
		//Удаляем нули с начала числа
		path_bigIntBeforeDot = delete_null(path_bigIntBeforeDot);
		path_bigIntAfterDot = delete_null(path_bigIntAfterDot);
		path_bigInt2BeforeDot = delete_null(path_bigInt2BeforeDot);
		path_bigInt2ArterDot = delete_null(path_bigInt2ArterDot);
		//Сраниваем целые части
		// Сравнение отрицательных чисел

		if (has_minus(path_bigIntBeforeDot) == true && has_minus(path_bigInt2BeforeDot) == false) {
			return "Less";
		}
		else if (has_minus(path_bigIntBeforeDot) == false && has_minus(path_bigInt2BeforeDot) == true) {
			return "More";
		}
		else if (has_minus(path_bigIntBeforeDot) == true && has_minus(path_bigInt2BeforeDot) == true) {
			int i = 0;

			while ((path_bigIntBeforeDot[i] - '0') == (path_bigInt2BeforeDot[i] - '0')) {
				i++;
			}
			if ((path_bigIntBeforeDot[i] - '0') == (path_bigInt2BeforeDot[i] - '0')) {
				return "Equal";
			}

			if ((path_bigIntBeforeDot[i] - '0') <= (path_bigInt2BeforeDot[i] - '0')) {
				return "Less";
			}


			if ((path_bigIntBeforeDot[i] - '0') >= (path_bigInt2BeforeDot[i] - '0')) {
				return "More";
			}

		}

		return "Not numbers";
	}
}

//Проверка на вешественные числа
bool checkingNumbers(std::string number)
{

	int dot_pos = -1;

	bool digit_found = false;

	for (int i = 0; i < number.size(); ++i) {

		char ch = number[i];



		if (ch >= '0' && ch <= '9') {

			digit_found = true;

			continue;

		}

		else if (ch == '.') {

			if (dot_pos != -1) {

				std::cout << "Incorrect number of dot\n";

				return false;

			}

			else {

				dot_pos = i;

				continue;

			}

		}

		else if (ch == '-' && i == 0) {

			continue;

		}



		std::cout << "Incorrect symbol " << ch << '\n';

		return false;



	}

	if (!digit_found) {

		std::cout << "There is no digit in number\n";

		return false;

	}



	return true;

}
