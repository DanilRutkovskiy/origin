#pragma once
#include "Triangle.hpp"

class SHAPE_API RightTriangle : public Triangle {
public:
	RightTriangle();
	RightTriangle(double a, double b, double c, double A, double B);
public:
	virtual bool check_figure() const override;
};
