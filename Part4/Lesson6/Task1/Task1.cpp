#include <iostream>
#include <string>

int simple_string_hash(std::string str) {
    int ret = 0;
    for (int i = 0; i < str.size(); i++)
        ret += static_cast<int>(str[i]);

    return ret;
}

int main()
{
    std::string str{""};
    while (str != "exit") {
        std::cout << "Input a string: ";
        std::getline(std::cin, str);
        std::cout << "String hash: " << simple_string_hash(str) << std::endl;
    }

    return 0;
}