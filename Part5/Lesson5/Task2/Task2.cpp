#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

int main()
{
    std::set<int> st;
    int count;
    std::cout << "IN:" << std::endl;
    std::cin >> count;

    while (count > 0) {
        int val;
        std::cin >> val;
        st.insert(val);
        --count;
    }

    std::vector<int> vec{ st.begin(), st.end() };

    std::sort(vec.begin(), vec.end(), [](int el1, int el2) {
        return el1 > el2;
        });

    std::cout << "OUT" << std::endl;
    for (const auto& el : vec)
        std::cout << el << std::endl;

    return 0;
}