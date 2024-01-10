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
		std::cout << "Введите номер месяца: ";
		std::cin >> in;

		Month inn = static_cast<Month>(in);

		switch (inn)
		{
		case Month::Jan:
			std::cout << "Январь" << std::endl;
			break;
		case Month::Feb:
			std::cout << "Февраль" << std::endl;
			break;
		case Month::Marth:
			std::cout << "Март" << std::endl;
			break;
		case Month::April:
			std::cout << "Апрель" << std::endl;
			break;
		case Month::May:
			std::cout << "Май" << std::endl;
			break;
		case Month::June:
			std::cout << "Июнь" << std::endl;
			break;
		case Month::Jule:
			std::cout << "Июль" << std::endl;
			break;
		case Month::Augest:
			std::cout << "Август" << std::endl;
			break;
		case Month::Sept:
			std::cout << "Сентябрь" << std::endl;
			break;
		case Month::Oct:
			std::cout << "Октябрь" << std::endl;
			break;
		case Month::Nov:
			std::cout << "Ноябрь" << std::endl;
			break;
		case Month::Dec:
			std::cout << "Декабрь" << std::endl;
			break;
		default:
			std::cout << "Неверный номер месяца" << std::endl;
			break;
		}
	}

	return 0;
}