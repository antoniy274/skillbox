// mobile_phone.cpp: определяет точку входа для приложения.

#include "mobile_phone.h"
#include <iostream>
#include <string>
#include <map>

#define ADD_NAME "add"
#define CALL_NAME "call"
#define SMS_NAME "sms"
#define EXIT_NAME "exit"


enum Commands {
    ADD = 1,
    CALL,
    SMS,
    EXIT
};

using namespace std;

int main()
{
    int i;
    MobilePhone phone;


    map<string, int> commands;
    commands[ADD_NAME] = Commands::ADD;
    commands[CALL_NAME] = Commands::CALL;
    commands[SMS_NAME] = Commands::SMS;
    commands[EXIT_NAME] = Commands::EXIT;

    while (true) {
        string inputCommand;

        cout << "Enter the command:\n";
        cin >> inputCommand;

        switch (commands[inputCommand]) {
        case Commands::ADD: {
            string name;
            string phoneNumber;

            cout << "Enter name and phone number\n";
            cin >> name >> phoneNumber;

            while (!phone.isPhoneNumber(phoneNumber)) {
                cout << "Invalid phone number. Enter valid phone number:\n";
                cin >> phoneNumber;
            }

            phone.add(name, phoneNumber);
            break;
        }
        case Commands::CALL: {
            string value;

            cout << "Enter the name or phone number of contact\n";
            cin >> value;

            phone.call(value);
            break;
        }
        case Commands::SMS: {
            string value;
            string message;

            cout << "Enter the name or phone number of contact and message\n";
            cin >> value >> message;

            phone.sms(value, message);
            break;
        }
        case Commands::EXIT: {
            return 0;
        }
        default: {
            cout << "Wrong command.\n";
        }
        }
    }
}
