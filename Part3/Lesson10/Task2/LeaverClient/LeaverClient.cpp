#include <iostream>
#include "..\Leaver\Leaver.hpp"

int main()
{
    Leaver::Leaver leaver_obj;
    std::cout << "Enter name:";
    std::string name;
    std::cin >> name;
    leaver_obj.leave(name);

    return 0;
}
