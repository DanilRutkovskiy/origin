#pragma once
#include "Triangle.hpp"

class RightTriangle : public Triangle {
public:
	RightTriangle() : Triangle(1, 2, 3, 45, 45, 90, "������������� �����������") {};
	RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90, "������������� �����������") {};
public:
	virtual bool check_figure() const override;
};
