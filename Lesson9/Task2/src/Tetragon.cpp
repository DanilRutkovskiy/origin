#include "Tetragon.hpp"
#include <iostream>

bool Tetragon::check_figure() const {
	return get_edge_count() == 4 && (get_A() + get_B() + get_C() + get_D()) == 360;
}

void Tetragon::print_info() const {
	Shape::print_info();
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << " ,d=" << m_d << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << " ,D=" << m_D << std::endl;
}