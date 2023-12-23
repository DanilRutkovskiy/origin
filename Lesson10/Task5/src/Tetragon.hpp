#pragma once
#include "Shape.hpp"

class SHAPE_API Tetragon : public Shape {
public:
	Tetragon();
	Tetragon(double a, double b, double c, double d, double A, double B, double C, double D);
	~Tetragon();

public:
	virtual bool check_figure() const override;
	virtual void print_info() const override;

	virtual double get_a() const;
	virtual double get_b() const;
	virtual double get_c() const;
	virtual double get_d() const;

	virtual double get_A() const;
	virtual double get_B() const;
	virtual double get_C() const;
	virtual double get_D() const;

protected:
	Tetragon(double a, double b, double c, double d, double A, double B, double C, double D, const char* name);

private:
	double m_a, m_b, m_c, m_d;//Стороны
	double m_A, m_B, m_C, m_D;//Углы
};

