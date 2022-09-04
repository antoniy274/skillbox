#include <iostream>
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

bool MobilePhone::isPhoneNumber(std::string value) {
    if (value.length() == 12) {
        for (int i = 1; i < 12; i++) {
            if (!isdigit(value[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void MobilePhone::add(std::string name, std::string number) {
    Address address;
    address.setName(name);
    address.setPhoneNumber(number);

    addressBookNames.insert(std::pair<std::string, Address>(name, address));
    addressBookPhones.insert(std::pair<std::string, Address>(number, address));

}

void MobilePhone::call(std::string value) {
     //Глобально объявить переменную user не получилось, так как не знаю её тип.
    if (isPhoneNumber(value)) {
        if (addressBookPhones.find(value) != addressBookPhones.end()) {
           auto user = addressBookPhones.find(value);
           std::cout << "CALL to " << user->second.getName() << " on number " << user->second.getPhoneNumber() << std::endl;
        }
        else {
            std::cout << "Invalid phone number\n";
            return;
        }

    }
    else {
        if (addressBookNames.find(value) != addressBookNames.end()) {
            auto user = addressBookNames.find(value);
            std::cout << "CALL to " << user->second.getName() << " on number " << user->second.getPhoneNumber() << std::endl;
        }
        else {
            std::cout << "Invalid phone number\n";
            return;
        }
    }
}

void MobilePhone::sms(std::string value, std::string message) {
    if (isPhoneNumber(value)) {
        if (addressBookPhones.find(value) != addressBookPhones.end()) {
            auto user = addressBookPhones.find(value);
            std::cout << "Message: \n" << message << "\n sent to " << user->second.getName()
                << " on number " << user->second.getPhoneNumber() << std::endl;
        }
        else {
            std::cout << "Invalid phone number\n";
            return;
        }

    }
    else {
        if (addressBookNames.find(value) != addressBookNames.end()) {
            auto user = addressBookNames.find(value);
            std::cout << "Message: \n" << message << "\n sent to " << user->second.getName()
                << " on number " << user->second.getPhoneNumber() << std::endl;
        }
        else {
            std::cout << "Invalid phone number\n";
            return;
        }
    }
}
