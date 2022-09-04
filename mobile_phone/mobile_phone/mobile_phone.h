#pragma once
#include <map>
#include <string>
/*Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта.Оба эти параметра команда получает от пользователя через стандартный ввод.

Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить.
Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.

Команда sms.Запрашивает у пользователя номер телефона(или имя контакта), на который требуется послать сообщение.Само сообщение также вводится через стандартный ввод.
Команда exit — выход из программы.*/

class Address {
    std::string name;
    std::string phone;
public:

    std::string getName();
    std::string getPhoneNumber();
    void setName(std::string value);
    void setPhoneNumber(std::string value);
};

class MobilePhone {
private:

    std::map<std::string, Address> addressBookNames;
    std::map<std::string, Address> addressBookPhones;
	std::string command;
public:
    bool isPhoneNumber(std::string value);
	void add(std::string name, std::string number);
	void call(std::string str);
	void sms(std::string str, std::string message);
};