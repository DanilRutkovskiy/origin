#include <iostream>

void print(int* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

int pivot(int* arr, int size) {
    int piv = arr[size / 2];

    int l_i = 0;
    int r_i = size - 1;
    int l_v, r_v;

    while (l_i < r_i) {
        l_v = arr[l_i];
        r_v = arr[r_i];

        if (l_v < piv) {
            l_i++;
            continue;
        }

        if (r_v > piv) {
            r_i--;
            continue;
        }

        std::swap(l_v, r_v);
        arr[l_i] = l_v;
        arr[r_i] = r_v;
        l_i++;
        r_i--;
    }

    return l_i;
}

void quick_sort(int* arr, int size) {
    if (size <= 1)
        return;

    int l_s = pivot(arr, size);
    int r_s = size - l_s;

    int* l = arr;
    int* r = arr + l_s;

    quick_sort(l, l_s);
    quick_sort(r, r_s);
}

int main()
{
    int size = 10;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = std::rand() % 100;
    std::cout << "Before sort: ";
    print(arr, size);

    quick_sort(arr, size);

    std::cout << std::endl << "After sort: ";
    print(arr, size);

    return 0;
}
