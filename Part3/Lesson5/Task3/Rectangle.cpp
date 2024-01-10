#include "Rectangle.hpp"
bool Rectangle::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_c()) && (get_b() == get_d()) &&
		(get_A() == 90) && (get_B() == 90) && (get_C() == 90) && (get_D() == 90);
}