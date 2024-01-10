#include "RightTriangle.hpp"

bool RightTriangle::check_figure() const {
	return Triangle::check_figure() && (get_C() == 90);
}