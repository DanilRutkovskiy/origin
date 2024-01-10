#include "Rectangle.hpp"
Rectangle::Rectangle() : Tetragon(2, 4, 2, 4, 90, 90, 90, 90, "Прямоугольник") {}
Rectangle::Rectangle(double ac, double bd) : Tetragon(ac, bd, ac, bd, 90, 90, 90, 90, "Прямоугольник") {}
Rectangle::~Rectangle(){};

bool Rectangle::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_c()) && (get_b() == get_d()) &&
		(get_A() == 90) && (get_B() == 90) && (get_C() == 90) && (get_D() == 90);
}