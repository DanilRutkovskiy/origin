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

bool remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
    if (logical_size == 0) {
        return false;
    }
    else if (logical_size <= actual_size / 3) {
        actual_size /= 3;
        int* temp = new int[actual_size];
        for (int i = 1; i < logical_size; i++)
            temp[i - 1] = arr[i];

        --logical_size;
        delete[] arr;
        arr = temp;
        return true;
    }
    else {
        for (int i = 1; i < logical_size; i++)
            arr[i - 1] = arr[i];

        logical_size--;
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
    bool del = true;
    while (true) {
        std::cout << "Delete element? y/n: ";
        char ans;
        std::cin >> ans;
        if (std::tolower(ans) == 'n') {
            break;
        }
        if (!remove_dynamic_array_head(arr, logical_size, actual_size))
            std::cout << "Can't remove element!" << std::endl;

        std::cout << "Thank you, your array: ";
        print_dynamic_array(arr, logical_size, actual_size);
        std::cout << std::endl;
    }
    delete[] arr;
    return 0;
}