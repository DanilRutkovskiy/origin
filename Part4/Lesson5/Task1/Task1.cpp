#include <iostream>

int get_index_lvl(int ind) {
   

    int lvl = 0;
    if (ind == 0)
        return lvl;
    lvl++;
    int counter = pow(2, lvl);

    while (ind > counter) {
        lvl++;
        counter += pow(2, lvl);
    }

    return lvl;
}

void print_pyramid(int* arr, int size) {
    if (size <= 0)
        return;

    std::cout << 0 << " root: " << arr[0] << std::endl;

    for (int i = 1; i < size; i++) {
        int lvl = get_index_lvl(i);

        if (i % 2 == 0)
            std::cout << lvl << " right:" << arr[i] << std::endl;
        else 
            std::cout << lvl << " left:" << arr[i] << std::endl;
    }
}

int main()
{
    int size = 0;
    std::cout << "Enter size: ";
    std::cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Enter " << i << "th element: ";
        std::cin >> arr[i];
    }

    print_pyramid(arr, size);

    delete[] arr;

    return 0;
}