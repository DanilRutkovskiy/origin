#include <iostream>

enum class Month {
	Jan,
	Feb,
	Marth,
	April,
	May,
	June,
	Jule,
	Augest,
	Sept,
	Oct,
	Nov,
	Dec
};

int main() {
	int in = -1;

	setlocale(LC_ALL, "Russian");

	while (in != 0) {
		std::cout << "������� ����� ������: ";
		std::cin >> in;

		Month inn = static_cast<Month>(in);

		switch (inn)
		{
		case Month::Jan:
			std::cout << "������" << std::endl;
			break;
		case Month::Feb:
			std::cout << "�������" << std::endl;
			break;
		case Month::Marth:
			std::cout << "����" << std::endl;
			break;
		case Month::April:
			std::cout << "������" << std::endl;
			break;
		case Month::May:
			std::cout << "���" << std::endl;
			break;
		case Month::June:
			std::cout << "����" << std::endl;
			break;
		case Month::Jule:
			std::cout << "����" << std::endl;
			break;
		case Month::Augest:
			std::cout << "������" << std::endl;
			break;
		case Month::Sept:
			std::cout << "��������" << std::endl;
			break;
		case Month::Oct:
			std::cout << "�������" << std::endl;
			break;
		case Month::Nov:
			std::cout << "������" << std::endl;
			break;
		case Month::Dec:
			std::cout << "�������" << std::endl;
			break;
		default:
			std::cout << "�������� ����� ������" << std::endl;
			break;
		}
	}

	return 0;
}