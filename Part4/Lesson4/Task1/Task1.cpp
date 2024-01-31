#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size){
    for (int i = 0; i < actual_size; i++) {
        if (i < logical_size)
            std::cout << arr[i];
        else
            std::cout << '_';

        std::cout << " ";
    }
       
}

int main()
{
    int logical_size = 0;
    int actual_size = 0;
    std::cout << "Input actual size: ";
    std::cin >> actual_size;
    std::cout << "Input logical size: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Error! Logical size is bigger than actual size";
        return 1;
    }

    int* arr = new int[actual_size];
    for (int i = 0; i < logical_size; i++) {
        std::cout << "Input arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
    return 0;
}