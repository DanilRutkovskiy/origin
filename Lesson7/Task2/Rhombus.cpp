#include "Rhombus.hpp"
bool Rhombus::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_c() == get_d()) &&
		(get_A() == get_C()) && (get_B() == get_D());
}

Rhombus::Rhombus() : Tetragon(4, 4, 4, 4, 60, 120, 60, 120, "Ромб") {};

Rhombus::Rhombus(double side, double ang_ac, double ang_bd) : Tetragon(side, side, side, side, ang_ac, ang_bd, ang_ac, ang_bd, "Ромб") 
{
	if (get_a() != get_b() || get_b() != get_c() || get_c() != get_d()) {
		bad_rhombus_side err;
		throw err;
	}

	if (get_A() != get_C() || get_B() != get_D()) {
		bad_rhombus_angle err;
		throw err;
	}
};