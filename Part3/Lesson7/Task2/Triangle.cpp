#include <iostream>
#include "Triangle.hpp"

Triangle::Triangle() : Shape{ 3, "Треугольник" }, m_a{ 1 }, m_b{ 2 }, m_c{ 3 }, m_A{ 20 }, m_B{ 60 }, m_C{ 100 } {};

Triangle::Triangle(double a, double b, double c, double A, double B, double C) :
	Shape{ 3, "Треугольник" }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C } 
{
	if (get_edge_count() != 3) {
		bad_triangle_side_count err;
		throw err;
	}
	if ((A + B + C) != 180) {
		bad_triangle_angle_sum err;
		throw err;
	}
};

Triangle::Triangle(double a, double b, double c, double A, double B, double C, std::string name) :
	Shape{ 3, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C } {

	if (get_edge_count() != 3) {
		bad_triangle_side_count err;
		throw err;
	}
	if ((A + B + C) != 180) {
		bad_triangle_angle_sum err;
		throw err;
	}

};

bool Triangle::check_figure() const {
	return (get_edge_count() == 3) && ((m_A + m_B + m_C) == 180);
}

void Triangle::print_info() const {
	Shape::print_info();
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << std::endl;
}