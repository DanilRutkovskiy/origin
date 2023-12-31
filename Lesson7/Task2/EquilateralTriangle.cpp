#include "EquilateralTriangle.hpp"

bool EquilateralTriangle::check_figure() const {
	return Triangle::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_A() == 60 && get_B() == 60 && get_C() == 60);
}

EquilateralTriangle::EquilateralTriangle() : Triangle(1, 1, 1, 60, 60, 60, "�������������� �����������") {};

EquilateralTriangle::EquilateralTriangle(double side, double angle) : Triangle(side, side, side, angle, angle, angle, "�������������� �����������")
{
	if (get_a() != get_b() || get_b() != get_c()) {
		bad_equilateral_triangle err;
		throw err;
	}
};