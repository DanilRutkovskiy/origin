#include "RightTriangle.hpp"

RightTriangle::RightTriangle() : Triangle(1, 2, 3, 45, 45, 90, "������������� �����������") {}
RightTriangle::RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90, "������������� �����������") {};

bool RightTriangle::check_figure() const {
	return Triangle::check_figure() && (get_C() == 90);
}