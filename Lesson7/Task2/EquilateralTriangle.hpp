#pragma once
#include "Triangle.hpp"

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle();
	EquilateralTriangle(double side, double angle);
public:
	virtual bool check_figure() const override;
};
