#include <iostream>
#include "Shape.hpp"

bool Shape::check_figure() const {
	return m_edge_count == 0;
}

void Shape::print_info() const {
	std::cout << get_name() << ":" << std::endl;
	std::cout << (check_figure() ? "Правильная" : "Неправильная") << std::endl;
	std::cout << "Количество сторон: " << m_edge_count << std::endl;
}