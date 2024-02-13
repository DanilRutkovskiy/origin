#include <iostream>
#include <string>

int real_string_hash(std::string str, int p, int n) {
    long long int ret = 0;
    for (int i = 0; i < str.size(); i++)
        ret += static_cast<int>(str[i]) * pow(p, i);

    return ret % n;
}

int main()
{
    std::string str{ "" };
    int p = 0;
    int n = 0;
    std::cout << "Input p: ";
    std::cin >> p;
    std::cout << "Input n: ";
    std::cin >> n;
    std::cin.ignore();
    while (str != "exit") {
        std::cout << "Input a string: ";
        std::getline(std::cin, str);
        std::cout << "String hash: " << real_string_hash(str, p, n) << std::endl;
    }

    return 0;
}