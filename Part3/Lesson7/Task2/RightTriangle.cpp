#include "RightTriangle.hpp"

bool RightTriangle::check_figure() const {
	return Triangle::check_figure() && (get_C() == 90);
}

RightTriangle::RightTriangle() : Triangle(1, 2, 3, 45, 45, 90, "Прямоугольный треугольник") {};

RightTriangle::RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {
	if (get_C() != 90) {
		bad_right_triangle err;
		throw err;
	}
};
