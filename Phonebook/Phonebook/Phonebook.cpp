#include <iostream>
#include <string>
#include <map>
#include <string>
#include <vector>

int getTypeOfRequest(std::string request);

int main()
{
    std::string request;
    std::string surname;
    std::string phone;
    std::map<std::string, std::string> phoneName;
    std::map<std::string, std::vector<std::string>> namePhones;

    std::cout << "Enter the request\n";
    std::getline(std::cin, request);

    switch (getTypeOfRequest(request)) {
    case 1: {
        phone = request.substr(0, request.find(' '));
        surname = request.substr(request.find(' ') + 1, request.length());

        auto item = namePhones.find(surname);
        phoneName.insert(make_pair(phone, surname));
        if (item == namePhones.end()) {
            namePhones.insert(make_pair(surname, std::vector<std::string>() = { phone }));
        }
        else {
            namePhones[item->first].push_back(phone);
        }
        std::cout << "Done!";
        break;
    }
    case 2: {
        auto item = phoneName.find(request);
        std::cout << item->second << std::endl;
        break;
    }
    case 3: {
        auto item = namePhones.find(request);
        for (int i = 0; i < item->second.size(); i++) {
            std::cout << item->second[i] << " ";
        }
        break;
    }
    }
}

int getTypeOfRequest(std::string request) {
    if (request.find(' ') != std::string::npos) return 1;
    else if (isdigit(request[0])) return 2;
    else return 3;
}