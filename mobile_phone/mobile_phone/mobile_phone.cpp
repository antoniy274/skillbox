#include <map>
#include <string>
#include "mobile_phone.h"
/*Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта.Оба эти параметра команда получает от пользователя через стандартный ввод.
Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить.Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.
Команда sms.Запрашивает у пользователя номер телефона(или имя контакта), на который требуется послать сообщение.Само сообщение также вводится через стандартный ввод.
Команда exit — выход из программы.*/

std::string Address::getName() {
    return name;
}

std::string Address::getPhoneNumber() {
    return phone;
}

void Address::setName(std::string value) {
    name = value;
}

void Address::setPhoneNumber(std::string value) {
    phone = value;
}

void MobilePhone::add(std::string name, std::string number) {
    Address address;
    address.setName(name);
    address.setPhoneNumber(number);

    addressBookNames.insert(std::pair<std::string, Address>(name, address));
    addressBookPhones.insert(std::pair<std::string, Address>(number, address));

}
