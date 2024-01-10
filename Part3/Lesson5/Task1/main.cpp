#include <iostream>
#include "mathFunctions.hpp"


int main() {
	setlocale(LC_ALL, "Russian");

	double n1, n2;
	std::cout << "¬ведите первое число: ";
	std::cin >> n1;
	std::cout << "¬ведите второе число: ";
	std::cin >> n2;
	std::cout << "¬ыберите операцию(1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	int act;
	std::cin >> act;
	switch (act) {
	case 1:
		std::cout << n1 << " + " << n2 << " = " << add(n1, n2) << std::endl;
		break;
	case 2:
		std::cout << n1 << " - " << n2 << " = " << substract(n1, n2) << std::endl;
		break;
	case 3:
		std::cout << n1 << " * " << n2 << " = " << multiply(n1, n2) << std::endl;
		break;
	case 4:
		std::cout << n1 << " / " << n2 << " = " << divide(n1, n2) << std::endl;
		break;
	case 5:
		std::cout << n1 << " * " << n2 << " = " << power(n1, n2) << std::endl;
		break;
	default:
		std::cout << "¬ыбрано вереное действие" << std::endl;
	}
	return 0;
}