#include <iostream>

class Calculator {
public:
	double add();
	double multiply();
	double substract_1_2();
	double substract_2_1();
	double divide_1_2();
	double divide_2_1();
	bool set_num1(double num1);
	bool set_num2(double num2);
private:
	double m_num_1;
	double m_num_2;
};

double Calculator::add() {
	return m_num_1 + m_num_2;
}

double Calculator::multiply() {
	return m_num_1 * m_num_2;
}

double Calculator::substract_1_2() {
	return m_num_1 - m_num_2;
}

double Calculator::substract_2_1() {
	return m_num_2 - m_num_1;
}

double Calculator::divide_1_2() {
	return m_num_1 / m_num_2;
}

double Calculator::divide_2_1() {
	return m_num_2 / m_num_1;
}

bool Calculator::set_num1(double num1) {
	if (num1 != 0) {
		m_num_1 = num1;
		return true;
	}
	else
		return false;
}

bool Calculator::set_num2(double num2) {
	if (num2 != 0) {
		m_num_2 = num2;
		return true;
	}
	else
		return false;
}

int main() {
	setlocale(LC_ALL, "Russian");

	Calculator calc;
	double temp;
	while (true) {
		std::cout << "Введите num1: ";
		std::cin >> temp;
		if (!calc.set_num1(temp)) {
			std::cout << "Неверный ввод" << std::endl;
			continue;
		}
		std::cout << "Введите num2: ";
		std::cin >> temp;
		if (!calc.set_num2(temp)) {
			std::cout << "Неверный ввод" << std::endl;
			continue;
		}
		
		std::cout << "num1 + num2: " << calc.add() << std::endl;
		std::cout << "num1 - num2: " << calc.substract_1_2() << std::endl;
		std::cout << "num2 - num1: " << calc.substract_2_1() << std::endl;
		std::cout << "num1 * num2: " << calc.multiply() << std::endl;
		std::cout << "num1 / num2: " << calc.divide_1_2() << std::endl;
		std::cout << "num2 / num1: " << calc.divide_2_1() << std::endl;

		std::cout << "1-no: ";
		std::cin >> temp;
		if (temp == 1) {
			break;
		}
	}
	return 0;
}