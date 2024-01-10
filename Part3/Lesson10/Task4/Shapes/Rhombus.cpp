#include "Rhombus.hpp"
Rhombus::Rhombus() : Tetragon(4, 4, 4, 4, 60, 120, 60, 120, "Ромб") {}
Rhombus::Rhombus(double side, double ang_ac, double ang_bd) : Tetragon(side, side, side, side, ang_ac, ang_bd, ang_ac, ang_bd, "Ромб") {}
Rhombus::~Rhombus(){};


bool Rhombus::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_c() == get_d()) &&
		(get_A() == get_C()) && (get_B() == get_D());
}