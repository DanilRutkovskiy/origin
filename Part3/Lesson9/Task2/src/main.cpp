#include <iostream>
#include "Shape.hpp"
#include "Triangle.hpp"
#include "RightTriangle.hpp"
#include "EquilateralTriangle.hpp"
#include "Tetragon.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Parallelogram.hpp"
#include "Rhombus.hpp"


int main() {
	setlocale(LC_ALL, "Russian");

	Triangle triang;
	std::cout << std::endl;
	triang.print_info();

	RightTriangle rt;
	std::cout << std::endl;
	rt.print_info();

	EquilateralTriangle et;
	std::cout << std::endl;
	et.print_info();

	Tetragon tetrag;
	std::cout << std::endl;
	tetrag.print_info();

	Rectangle rect;
	std::cout << std::endl;
	rect.print_info();

	Square squr;
	std::cout << std::endl;
	squr.print_info();

	Parallelogram par;
	std::cout << std::endl;
	par.print_info();

	Rhombus rhomb;
	std::cout << std::endl;
	rhomb.print_info();
	return 0;
}