#include "Parallelogram.hpp"
bool Parallelogram::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_c()) && (get_b() == get_d()) &&
		(get_A() == get_C()) && (get_B() == get_D());
}