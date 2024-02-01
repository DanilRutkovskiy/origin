#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; i++) {
        if (i < logical_size)
            std::cout << arr[i];
        else
            std::cout << '_';

        std::cout << " ";
    }

}

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int elem) {
    if (logical_size == actual_size) {
        actual_size *= 2;
        int* temp = new int[actual_size];
        for (int i = 0; i < logical_size; i++)
            temp[i] = arr[i];

        temp[logical_size++] = elem;

        delete[] arr;
        arr = temp;
    }
    else {
        arr[logical_size++] = elem;
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
    std::cout << std::endl;
    bool add = true;
    while (add) {
        std::cout << "Enter new array element: ";
        int elem;
        std::cin >> elem;
        append_to_dynamic_array(arr, logical_size, actual_size, elem);
        std::cout << "Thank you, your array: ";
        print_dynamic_array(arr, logical_size, actual_size);
        std::cout << std::endl;
        std::cout << "Add another element? y/n: ";
        char ans;
        std::cin >> ans;
        if (std::tolower(ans) != 'y')
            add = false;
    }
    delete[] arr;
    return 0;
}