#pragma once
#include "Shape.hpp"
class SHAPE_API Tetragon : public Shape {
public:
	Tetragon() : Shape{ 4, "Четырёхугольник" }, m_a{ 3 }, m_b{ 3 }, m_c{ 3 }, m_d{ 3 }, m_A{ 60 }, m_B{ 80 }, m_C{ 60 }, m_D{ 40 } {};
	Tetragon(double a, double b, double c, double d, double A, double B, double C, double D) :
		Shape{ 4, "Четырёхугольник" }, m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_A{ A }, m_B{ B }, m_C{ C }, m_D{ D } {};
	~Tetragon() {};

public:
	virtual bool check_figure() const override;
	virtual void print_info() const override;

	virtual double get_a() const { return m_a; };
	virtual double get_b() const { return m_b; };
	virtual double get_c() const { return m_c; };
	virtual double get_d() const { return m_d; };

	virtual double get_A() const { return m_A; };
	virtual double get_B() const { return m_B; };
	virtual double get_C() const { return m_C; };
	virtual double get_D() const { return m_D; };

protected:
	Tetragon(double a, double b, double c, double d, double A, double B, double C, double D, std::string name) :
		Shape{ 4, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_A{ A }, m_B{ B }, m_C{ C }, m_D{ D } {};



private:
	double m_a, m_b, m_c, m_d;//Стороны
	double m_A, m_B, m_C, m_D;//Углы
};

