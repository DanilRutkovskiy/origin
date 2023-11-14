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

	std::cout << "������� ����� �����: ";
	std::cin >> account.m_number;
	std::cout << "������� ��� ���������: ";
	std::cin >> account.m_name;
	std::cout << "������� ������: ";
	std::cin >> account.m_deposit;
	std::cout << "������� ����� ������: ";
	std::cin >> account.m_deposit;
	std::cout << "��� ����: " << account.m_name << ", " << account.m_number << ", " << account.m_deposit;
	
	return 0;
}