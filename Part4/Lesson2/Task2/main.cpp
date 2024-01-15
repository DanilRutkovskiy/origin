#include <iostream>

//Сложность по скорости O(n^2)
//Сложность по памяти O(1)

int fib(int n, int* arr) {
	if (n == 0)
		return 0;

	if (n == 1) {
		return 1;
	}

	if(arr[n] == -1){
		int num = fib(n - 1, arr) + fib(n - 2, arr);
		arr[n] = num;
	}

	return arr[n];
}

int main() {
	int num = 10;
	int* arr = new int[10];
	for (int i = 0; i < num; i++) {
		arr[i] = -1;
	}
	int a = fib(num - 1, arr);

	delete[] arr;
 	return 0;
}