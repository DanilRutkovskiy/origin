#include <iostream>

#define MODE 0

#ifndef MODE
#error "MODE �� ����������"
#endif // MODE

#if MODE == 1
double add(double n1, double n2) {
	return n1 + n2;
}
#endif


int main() {
	setlocale(LC_ALL, "Russian");

#if MODE == 0
	std::cout << "������� � ������ ����������" << std::endl;
#elif MODE == 1
	std::cout << "������� � ������ ������" << std::endl;
	double n1, n2;
	std::cout << "������� ����� 1: ";
	std::cin >> n1;
	std::cout << "������� ����� 2: ";
	std::cin >> n2;
	std::cout << "��������� ��������: " << add(n1, n2);
#else
	std::cout << "����������� �����. ���������� ������.";
#endif

	return 0;
}