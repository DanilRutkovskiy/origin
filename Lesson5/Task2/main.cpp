#include <iostream>
class Counter {
public:
	Counter() :m_count{ 1 } {};
	Counter(int count) : m_count{ count } {};
	Counter& operator++(int) { m_count++; return *this; }
	Counter& operator--(int) { m_count--; return *this; }
	int get_count() { return m_count; }

private:
	int m_count;
};

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� y ��� n: ";
	std::string temp;
	std::cin >> temp;
	int start_count = 1;

	if (temp == "y") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> start_count;
	}

	Counter count{ start_count };

	while (true) {
		std::cout << "������� �������:('+', '-', '=', 'x'): ";
		std::cin >> temp;
		if (temp == "+") {
			count++;
		}
		else if (temp == "-") {
			count--;
		}
		else if (temp == "=") {
			std::cout << count.get_count() << std::endl;;
		}
		else if (temp == "x") {
			std::cout << "�� ��������!";
			break;
		}
	}
	return 0;
}