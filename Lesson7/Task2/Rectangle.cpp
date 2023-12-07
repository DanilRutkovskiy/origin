#include "Rectangle.hpp"
bool Rectangle::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_c()) && (get_b() == get_d()) &&
		(get_A() == 90) && (get_B() == 90) && (get_C() == 90) && (get_D() == 90);
}

Rectangle::Rectangle() : Tetragon(2, 4, 2, 4, 90, 90, 90, 90, "Прямоугольник") {};

Rectangle::Rectangle(double ac, double bd) : Tetragon(ac, bd, ac, bd, 90, 90, 90, 90, "Прямоугольник") 
{
	if (get_a() != get_c() || get_b() != get_d()) {
		bad_rectangle_side_equality err;
		throw err;
	}

	if (get_A() != 90 || get_B() != 90 || get_C() != 90 || get_D() != 90) {
		bad_rectangle_angle err;
		throw err;
	}
};