#include <iostream>
#include "cpr/cpr.h"


int main()
{
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get/?foo=first&animal=cat&bar=second"));
	std::cout << r.text << "\n";

	std::string name, city;
	std::cin >> name >> city;
	cpr::Response rp = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload({ {"name", name.c_str()},
																					{"city",city.c_str()} }));
	std::cout << rp.text << "\n";
}
