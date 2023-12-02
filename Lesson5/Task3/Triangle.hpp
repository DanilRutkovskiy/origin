#pragma once
#include "Shape.hpp"

class Triangle : public Shape {
public:
	Triangle() : Shape{ 3, "Треугольник" }, m_a{ 1 }, m_b{ 2 }, m_c{ 3 }, m_A{ 20 }, m_B{ 60 }, m_C{ 100 } {};
	Triangle(double a, double b, double c, double A, double B, double C) :
		Shape{ 3, "Треугольник" }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C } {};
	~Triangle() {};

public:
	virtual void print_info() const override;
	virtual bool check_figure() const override;

	virtual double get_a() const { return m_a; };
	virtual double get_b() const { return m_b; };
	virtual double get_c() const { return m_c; };

	virtual double get_A() const { return m_A; };
	virtual double get_B() const { return m_B; };
	virtual double get_C() const { return m_C; };

protected:
	Triangle(double a, double b, double c, double A, double B, double C, std::string name) :
		Shape{ 3, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C } {};

private:
	double m_a, m_b, m_c;//Стороны
	double m_A, m_B, m_C;//Углы
};
