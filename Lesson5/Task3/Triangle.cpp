#include <iostream>
#include "Triangle.hpp"

bool Triangle::check_figure() const {
	return (get_edge_count() == 3) && ((m_A + m_B + m_C) == 180);
}

void Triangle::print_info() const {
	Shape::print_info();
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << std::endl;
}