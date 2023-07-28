#include <iostream>
#include "Registry.h"



int main()
{

    Registr<std::string, int> reg("test", 19);
    reg["test2"] = 55;
    reg["test56"] = 155;
    reg["tes"] = 365;
    reg.print();

    std::cout << "Find: " << reg.find("tesr") << std::endl;
    reg.remove("test56");
    reg.print();

    Registr<double, double> re(2.0, 1.2);
    re.add(13.321, 23.434);
    re.print();
    std::cout << "Find: " << re.find(13.321) << std::endl;
    re.remove(2.0);
    std::cout << "Find: " << re.find(0) << std::endl;
    re.print();
    return 0;
}