#include <iostream>
#include <vector>
#include <map>
#include "cpr/cpr.h"

bool request(const std::string query, const std::vector<cpr::Pair>& vec) {
	std::cout << "We send a request to the website, please wait..." << std::endl;
	if (query == "post") {
		cpr::Url url = cpr::Url{ "http://httpbin.org/" + query };
		cpr::Payload p(vec.begin(), vec.end());
		auto r = cpr::Post(url, p);
		std::cout << r.text << std::endl;
	}
	else
	{
		std::string arg = "?";
		for (int i = 0; i < vec.size();) {
			arg += vec[i].key + "=" + vec[i].value;
			++i;
			if (i != vec.size())
				arg += "&";
		}

		cpr::Url url = cpr::Url{ "http://httpbin.org/" + query + arg };
		auto r = cpr::Get(url);
		std::cout << r.text << std::endl;
	}
	return true;
}

int main()
{
	std::cout << "enter arguments and a post or get for the request: " << std::endl;
	std::string argf = "", args = "";
	bool exit = false;
	std::vector<cpr::Pair>vec;

	do {
		std::cout << "Enter first argument: ";
		std::cin >> argf;
		if (argf != "post" && argf != "get") {
			std::cout << "Enter second argument: ";
			std::cin >> args;
			if (args != "post" && args != "get") {
				vec.push_back({ argf, args });
			}
			else {
				exit = request(args, vec);
			}
		}
		else {
			exit = request(argf, vec);
		}
	} while (!exit);
}
