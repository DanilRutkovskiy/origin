#pragma once
#include "Shape.hpp"

class Triangle : public Shape {
public:
	Triangle();
	Triangle(double a, double b, double c, double A, double B, double C);
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
	Triangle(double a, double b, double c, double A, double B, double C, std::string name);

private:
	double m_a, m_b, m_c;//Стороны
	double m_A, m_B, m_C;//Углы
};
