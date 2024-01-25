#include <iostream>

void merge(int* arr1, int s1, int* arr2, int s2) {
    int* arr = new int[s1 + s2];
    int arr1_ind = 0;
    int arr2_ind = 0;
    int arr_ind = 0;

    while (arr1_ind < s1 || arr2_ind < s2) {
        if (arr1_ind == s1) {
            arr[arr_ind] = arr2[arr2_ind];
            arr2_ind++;
            arr_ind++;
            continue;
        }

        if (arr2_ind == s2) {
            arr[arr_ind] = arr1[arr1_ind];
            arr1_ind++;
            arr_ind++;
            continue;
        }

        if (arr1[arr1_ind] > arr2[arr2_ind]) {
            arr[arr_ind] = arr1[arr1_ind];
            arr1_ind++;
        }
        else {
            arr[arr_ind] = arr2[arr2_ind];
            arr2_ind++;
        }
        arr_ind++;
    }

    for (int i = 0; i < s1 + s2; i++)
        arr1[i] = arr[i];

    delete[] arr;
}

void merge_sort(int* arr, int size) {
    if (size == 1)
        return;

    int s1 = size / 2;
    int s2 = size - s1;

    int* arr1 = arr;
    int* arr2 = arr + s1;

    merge_sort(arr1, s1);
    merge_sort(arr2, s2);

    merge(arr1, s1, arr2, s2);
}

void print(int* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

int main()
{
    int size = 10;
    int* arr = new int[size];
    arr[0] = 3;arr[1] = 0;
    arr[2] = 4;arr[3] = 2;
    arr[4] = 9;arr[5] = 6;
    arr[6] = 7;arr[7] = 5;
    arr[8] = 8;arr[9] = 1;

    std::cout << "Initial array: ";
    print(arr, size);
    std::cout << std::endl;
    merge_sort(arr, 10);
    std::cout << "Current array: ";
    print(arr, size);
    std::cout << std::endl;
    delete[] arr;
}
