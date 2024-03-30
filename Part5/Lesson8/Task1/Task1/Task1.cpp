#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T>& vec1, std::vector<T>& vec2) {
    std::vector<T> temp = std::move(vec1);
    vec1 = std::move(vec2);
    vec2 = std::move(temp);
}

int main()
{
    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 2, 5, 6, 7, 9 };

    move_vectors(vec1, vec2);

    return 0;
}