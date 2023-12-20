#pragma once
#include "Triangle.hpp"

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle() : Triangle(1, 1, 1, 60, 60, 60, "Равносторонний треугольник") {};
	EquilateralTriangle(double side, double angle) : Triangle(side, side, side, angle, angle, angle, "Равносторонний треугольник") {};
public:
	virtual bool check_figure() const override;
};
