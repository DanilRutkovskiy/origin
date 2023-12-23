#include <iostream>
#include "Triangle.hpp"

bool Triangle::check_figure() const {
	return (get_edge_count() == 3) && ((m_A + m_B + m_C) == 180);
}

double Triangle::get_a() const
{
	return m_a;
}

double Triangle::get_b() const
{
	return m_b;
}

double Triangle::get_c() const
{
	return m_c;
}

double Triangle::get_A() const
{
	return m_A;
}

double Triangle::get_B() const
{
	return m_B;
}

double Triangle::get_C() const
{
	return m_C;
}

Triangle::Triangle(double a, double b, double c, double A, double B, double C, const char* name) : Shape{ 3, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C }
{
}

Triangle::Triangle() : Shape{ 3, "Треугольник" }, m_a{ 1 }, m_b{ 2 }, m_c{ 3 }, m_A{ 20 }, m_B{ 60 }, m_C{ 100 }
{
}

Triangle::Triangle(double a, double b, double c, double A, double B, double C) : Shape{ 3, "Треугольник" }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C }
{
}

Triangle::~Triangle()
{
}

void Triangle::print_info() const {
	Shape::print_info();
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << std::endl;
}