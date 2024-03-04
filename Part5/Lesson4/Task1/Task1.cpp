#include <iostream>
#include <vector>

template <typename T>
T my_sqr(T number) {
    return (number * number);
}

template <typename T>
std::vector<T> my_sqr(const std::vector<T>& vec) {
    std::vector<T> ret;
    ret.resize(vec.size());
    for (int i = 0; i < vec.size(); i++)
        ret[i] = vec[i] * vec[i];

    return ret;
}

int main()
{
    int a = 5;
    int b = my_sqr(a);

    std::vector<double> vec;
    vec.push_back(-1);
    vec.push_back(2);
    vec.push_back(4);

    std::cout << "Start vec: ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";

    auto new_vec = my_sqr(vec);
    std::cout << '\n' << "New vec: ";
    for (int i = 0; i < new_vec.size(); i++)
        std::cout << new_vec[i] << " ";

    return 0;
}