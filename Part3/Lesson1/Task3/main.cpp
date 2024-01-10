#include <iostream>

struct Address {
	std::string m_city;
	std::string m_street;
	int m_building_number;
	int m_flat_number;
	int m_index;
};

void printAddress(const Address& addr) {
	std::cout << "Город: " << addr.m_city << std::endl;
	std::cout << "Улица: " << addr.m_street<< std::endl;
	std::cout << "Номер дома: " << addr.m_building_number << std::endl;
	std::cout << "Номер квартиры: " << addr.m_flat_number << std::endl;
	std::cout << "Индекс: " << addr.m_index << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	Address addr1;
	addr1.m_city = "Tumen";
	addr1.m_street = "Kotelshikov";
	addr1.m_building_number = 2;
	addr1.m_flat_number = 100;
	addr1.m_index = 68048;

	Address addr2;
	addr2.m_city = "Tumen";
	addr2.m_street = "Kotelshikov";
	addr2.m_building_number = 3;
	addr2.m_flat_number = 101;
	addr2.m_index = 68048;

	printAddress(addr1);
	std::cout << std::endl;
	printAddress(addr2);

	return 0;
}