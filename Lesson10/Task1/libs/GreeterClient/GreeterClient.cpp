#include <iostream>
#include "..\Greeter\Greeter.hpp"

int main()
{
    GreeterNS::Greeter greeter_obj;
    std::cout << "Enter name: ";
    std::string name;
    std::cin >> name;
    greeter_obj.greet(name);
    return 0;
}
