#include <iostream>
#include <array>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>

int main()
{
    std::string str;
    std::getline(std::cin, str);

    std::map<char, int> map;

    for (const auto& el : str)
        map[el]++;

    std::vector<std::pair<char, int>> vec{map.begin(), map.end()};

    std::sort(vec.begin(), vec.end(), [](std::pair<char, int> p1, std::pair<char, int> p2) {
        return p1.second > p2.second;
        });

    for (const auto& el : vec)
        std::cout << el.first << ": " << el.second << std::endl;

    return 0;
}