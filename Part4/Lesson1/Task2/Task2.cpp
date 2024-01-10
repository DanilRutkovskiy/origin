#include <iostream>
#include <vector>

int count(const std::vector<int>& vec, int num) {
    int size = vec.size();
    if (size == 0)
        return 0;
    if (vec[0] > num)
        return size;

    int left = 0;
    int right = vec.size() - 1;
    int ind = (left + right) / 2;
    while (left < right) {
        if (num > vec[ind]) {
            left = ind + 1;
        }
        else if (num < vec[ind]) {
            right = ind - 1;
        }
        else {
            while ((vec[ind] == vec[ind + 1]) && (ind < size - 1))
                ind++;

            continue;
        }

        ind = (left + right) / 2;
    }

    return size - (ind + 1);
}

int main()
{
    std::vector<int> vec{ 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;
    int c = count(vec, num);
    std::cout << "Count of elements larger than " << num << ": " << c;
}