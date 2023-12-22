#pragma once
#include "Shape.hpp"

class SHAPE_API Triangle : public Shape {
public:
	Triangle(); 
	Triangle(double a, double b, double c, double A, double B, double C);
	~Triangle();

public:
	virtual void print_info() const override;
	virtual bool check_figure() const override;

	virtual double get_a() const;
	virtual double get_b() const;
	virtual double get_c() const;

	virtual double get_A() const;
	virtual double get_B() const;
	virtual double get_C() const;

protected:
	Triangle(double a, double b, double c, double A, double B, double C, const char* name);

private:
	double m_a, m_b, m_c;//Стороны
	double m_A, m_B, m_C;//Углы
};