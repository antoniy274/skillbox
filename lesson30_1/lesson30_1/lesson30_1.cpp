#include "iostream"
#include "cpr/cpr.h"


int main()
{
	std::string str;
	
	std::cout << "Enter the commands: <<get>>, <<post>>, <<put>>, <<delete>>, <<patch>>"
		<< " or enter the command << exit >> to exit" << "\n";

	while (std::getline(std::cin, str) && str != "exit") {
		
		cpr::Response r;
		if (str == "get") {
			r = cpr::Get(cpr::Url("http://httpbin.org/get"));
			std::cout << r.text << "\n";
		}
		else if (str == "post") {
			r = cpr::Post(cpr::Url("http://httpbin.org/post"));
			std::cout << r.text << "\n";
		}
		else if (str == "put") {
			r = cpr::Put(cpr::Url("http://httpbin.org/put"));
			std::cout << r.text << "\n";
		}
		else if (str == "delete") {
			r = cpr::Put(cpr::Url("http://httpbin.org/delete"));
			std::cout << r.text << "\n";
		}
		else if (str == "patch") {
			r = cpr::Put(cpr::Url("http://httpbin.org/patch"));
			std::cout << r.text << "\n";
		}

		std::cout << "Enter the commands: <<get>>, <<post>>, <<put>>, <<delete>>, <<patch>>" 
			<<" or enter the command << exit >> to exit" << "\n";
	}
}