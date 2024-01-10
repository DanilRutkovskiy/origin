#include <iostream>

struct BankAccount {
	int m_number;
	std::string m_name;
	double m_deposit;
};

void change_deposit(BankAccount& acc, double new_deposit) {
	acc.m_deposit = new_deposit;
}

int main() {
	setlocale(LC_ALL, "Russian");
	BankAccount account;

	std::cout << "¬ведите номер счета: ";
	std::cin >> account.m_number;
	std::cout << "¬ведите им€ владельца: ";
	std::cin >> account.m_name;
	std::cout << "¬ведите баланс: ";
	std::cin >> account.m_deposit;
	std::cout << "¬ведите новый баланс: ";
	std::cin >> account.m_deposit;
	std::cout << "¬аш счет: " << account.m_name << ", " << account.m_number << ", " << account.m_deposit;
	
	return 0;
}