#include <iostream>
#include "Shape.hpp"

bool Shape::check_figure() const {
	return m_edge_count == 0;
}

void Shape::print_info() const {
	std::cout << get_name() << ":" << std::endl;
	std::cout << (check_figure() ? "����������" : "������������") << std::endl;
	std::cout << "���������� ������: " << m_edge_count << std::endl;
}