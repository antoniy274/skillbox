/*Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4).
IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов,
причём каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих нулей.
Других символов в строке, кроме вышеописанных, присутствовать не должно.

Пользователь вводит строку, задающую ip-адрес. Программа должна вывести слово Yes, если адрес корректен, и слово No, если это не так.*/

#include <iostream>
#include <string>
#include <cctype>

bool ip_validation(std::string ip);
int ipNumber(std::string str);

int main() {
	std::string ip;
	std::cin >> ip;

	if (ip_validation(ip)) {
		std::cout << "Yes" << '\n';
	}
	else
		std::cout << "No" << '\n';

}

bool ip_validation(std::string s) {
	s.push_back('.');
	std::string delimiter = ".";
	int number = 0;
	int pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		for (int i = 0; i < token.size() ; i++) {
			if (!isdigit(token[i]) || token.size() > 3 || token[i] == ' ') {
				return false;
			}
			else if (token.size() > 1 && token[0] == '0') {
				return false;
			}
			else if (ipNumber(token) > 256) {
				return false;
			}
		}
		
		s.erase(0, pos + delimiter.length());
	}
	return true;
}

int ipNumber(std::string str) {
	int number = 0;
	if (str.size() == 3) {
		int a = ((str[0]) - '0') * 100;
		int b = ((str[1]) - '0') * 10;
		int c = ((str[2]) - '0');
		number = a + b + c;
	}
	if (str.size() == 2) {
		int b = ((str[0]) - '0') * 10;
		int c = ((str[1]) - '0');
		number = b + c;
	}
	if (str.size() == 1) {
		int c = ((str[0]) - '0');
		number = c;
	}
	return number;
}