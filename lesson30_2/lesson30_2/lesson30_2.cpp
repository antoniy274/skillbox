#include "iostream"
#include "cpr/cpr.h";

int main()
{
	cpr::Response r;
	r = cpr::Get(cpr::Url("http://httpbin.org/get"));
	std::cout << r.text << "\n";
}
