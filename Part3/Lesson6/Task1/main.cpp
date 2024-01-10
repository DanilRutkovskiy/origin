#include <iostream>

#define MODE 0

#ifndef MODE
#error "MODE не определена"
#endif // MODE

#if MODE == 1
double add(double n1, double n2) {
	return n1 + n2;
}
#endif


int main() {
	setlocale(LC_ALL, "Russian");

#if MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
	std::cout << "Работаю в боевом режиме" << std::endl;
	double n1, n2;
	std::cout << "Введите число 1: ";
	std::cin >> n1;
	std::cout << "Введите число 2: ";
	std::cin >> n2;
	std::cout << "Результат сложения: " << add(n1, n2);
#else
	std::cout << "Неизвестный режим. Завершение работы.";
#endif

	return 0;
}