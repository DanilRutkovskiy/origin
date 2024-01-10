#pragma once
#include "Triangle.hpp"

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle() : Triangle(1, 1, 1, 60, 60, 60, "�������������� �����������") {};
	EquilateralTriangle(double side, double angle) : Triangle(side, side, side, angle, angle, angle, "�������������� �����������") {};
public:
	virtual bool check_figure() const override;
};
