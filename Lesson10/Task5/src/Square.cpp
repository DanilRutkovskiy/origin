#include "Square.hpp"
#include <iostream>
Square::Square() : Tetragon(4, 4, 4, 4, 90, 90, 90, 90, "�������") {}
Square::Square(double side) : Tetragon(side, side, side, side, 90, 90, 90, 90, "�������") {}
Square::~Square(){};

bool Square::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_c() == get_d()) &&
		(get_A() == 90) && (get_B() == 90) && (get_C() == 90) && (get_D() == 90);
}
