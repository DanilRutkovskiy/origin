#include "Tetragon.hpp"
#include <iostream>

Tetragon::Tetragon() : Shape{ 4, "Четырёхугольник" }, m_a{ 3 }, m_b{ 3 }, m_c{ 3 }, m_d{ 3 }, m_A{ 60 }, m_B{ 80 }, m_C{ 60 }, m_D{ 40 }
{
}

Tetragon::Tetragon(double a, double b, double c, double d, double A, double B, double C, double D) : Shape { 4, "Четырёхугольник" }, m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_A{ A }, m_B{ B }, m_C{ C }, m_D{ D } 
{
}
Tetragon::~Tetragon()
{
}
;

bool Tetragon::check_figure() const {
	return get_edge_count() == 4 && (get_A() + get_B() + get_C() + get_D()) == 360;
}

void Tetragon::print_info() const {
	Shape::print_info();
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << " ,d=" << m_d << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << " ,D=" << m_D << std::endl;
}

double Tetragon::get_a() const
{
	return m_a;
}

double Tetragon::get_b() const
{
	return m_b;
}

double Tetragon::get_c() const
{
	return m_c;
}

double Tetragon::get_d() const
{
	return m_d;
}

double Tetragon::get_A() const
{
	return m_A;
}

double Tetragon::get_B() const
{
	return m_B;
}

double Tetragon::get_C() const
{
	return m_C;
}

double Tetragon::get_D() const
{
	return m_D;
}

Tetragon::Tetragon(double a, double b, double c, double d, double A, double B, double C, double D, const char* name) : Shape{ 4, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_A{ A }, m_B{ B }, m_C{ C }, m_D{ D } 
{
};
