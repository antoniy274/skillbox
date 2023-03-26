#include "iostream"
#include "cpr/cpr.h";

int main()
{
	cpr::Response r;
	r = cpr::Get(cpr::Url("http://httpbin.org/html"), cpr::Header{ {"accept", "text/html"} });
	std::string str = "<h1>";
	auto begin = r.text.find("<h1>") + str.size();
	auto end = r.text.find("</h1>", begin - 1) - begin;
	std::cout << r.text.substr(begin, end) << "\n";
}
