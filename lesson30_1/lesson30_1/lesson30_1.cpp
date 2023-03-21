// lesson30_1.cpp: определяет точку входа для приложения.
//

#include "lesson30_1.h"
#include "iostream"
#include "cpr/cpr.h"


int main()
{
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
	std::cout << r.text << "\n";
}