#include "EquilateralTriangle.hpp"

bool EquilateralTriangle::check_figure() const {
	return Triangle::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_A() == 60 && get_B() == 60 && get_C() == 60);
}