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

const char* get_index_pos(int ind) {
    if (ind == 0) {
        return "root";
    }
    else if (ind % 2 == 0) {
        return "right";
    }
    else {
        return "left";
    }
}

void print_pyramid(int* arr, int size) {
    if (size <= 0)
        return;

    std::cout << 0 << " root: " << arr[0] << std::endl;

    for (int i = 1; i < size; i++) {
        int lvl = get_index_lvl(i);

        std::cout << lvl << " " << get_index_pos(i) << ": " << arr[i] << std::endl;
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

    int act = 0;
    int ind = 0;
    while (act != 4) {
        std::cout << "You are here: " << get_index_lvl(ind) << " " << get_index_pos(ind) << ": " << arr[ind] << std::endl;
        std::cout << "Enter command(1 - Up, 2 - Left, 3 - Right, 4 - Exit): ";
        std::cin >> act;
        if (act == 1) {
            ind = (ind - 1) / 2;

            if (ind < 0) {
                std::cout << "Error! There is no parent." << std::endl;
                ind = 0;
            }
        }
        else if (act == 2) {
            ind = 2 * ind + 1;
            if (ind >= size) {
                std::cout << "Error! There is no left child." << std::endl;
                ind = (ind - 1) / 2;
            }
        }
        else if (act == 3) {
            ind = 2 * ind + 2;
            if (ind >= size) {
                std::cout << "Error! There is no right child." << std::endl;
                ind = (ind - 2) / 2;
            }
        }
        else {
            break;
        }
    }

    delete[] arr;

    return 0;
}