#include <map>
#include <string>
#include "mobile_phone.h"
/*������� add ��������� � �������� ����� ����� ����� �������� � ����������� ��� � ������ ��������.��� ��� ��������� ������� �������� �� ������������ ����� ����������� ����.
������� call ����������� � ������������ ��� �������� ��� ����� ��������, �� ������� ��������� ���������.��� �� ���� ������ ������������ � ������� ������ � ������� ��������� CALL � ������� ��������, �� ������� �������������� �����.
������� sms.����������� � ������������ ����� ��������(��� ��� ��������), �� ������� ��������� ������� ���������.���� ��������� ����� �������� ����� ����������� ����.
������� exit � ����� �� ���������.*/

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
