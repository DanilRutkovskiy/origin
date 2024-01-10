#include "Parallelogram.hpp"
bool Parallelogram::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_c()) && (get_b() == get_d()) &&
		(get_A() == get_C()) && (get_B() == get_D());
}

Parallelogram::Parallelogram() : Tetragon(2, 4, 2, 4, 60, 120, 60, 120, "ֿאנאככוכמדנאלל") {};

Parallelogram::Parallelogram(double ac, double bd, double ang_ac, double ang_bd) : Tetragon(ac, bd, ac, bd, ang_ac, ang_bd, ang_ac, ang_bd, "ֿאנאככוכמדנאלל") 
{
	if (get_A() != get_C() || get_B() != get_D()) {
		bad_parallelogram_angle err;
		throw err;
	}

	if (get_a() != get_c() || get_b() != get_d()) {
		bad_parallelogram_side err;
		throw err;
	}
};