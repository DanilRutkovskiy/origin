#include <iostream>
#include "mathFunctions.hpp"


int main() {
	setlocale(LC_ALL, "Russian");

	double n1, n2;
	std::cout << "������� ������ �����: ";
	std::cin >> n1;
	std::cout << "������� ������ �����: ";
	std::cin >> n2;
	std::cout << "�������� ��������(1 - ��������, 2 - ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
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
		std::cout << "������� ������� ��������" << std::endl;
	}
	return 0;
}