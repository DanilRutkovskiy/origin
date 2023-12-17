#include "Rhombus.hpp"
bool Rhombus::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_c() == get_d()) &&
		(get_A() == get_C()) && (get_B() == get_D());
}