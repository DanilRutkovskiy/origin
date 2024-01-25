#include <iostream>

void count_sort(int* arr, int size) {
    int count_arr[15];

    for (int i = 0; i < 15; i++) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count_arr[arr[i] - 10]++;
    }
    int ind = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < count_arr[i]; j++) {
            arr[ind++] = i + 10;
        }
    }
}

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    int size = 30;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 15 + 10;
    }

    std::cout << "Array before sorting: ";
    print(arr, size);
    count_sort(arr, size);
    std::cout << std::endl << "Array after sorting: ";
    print(arr, size);

    delete[] arr;
    return 0;
}
