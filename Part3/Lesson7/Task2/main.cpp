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
	try {
		Triangle triang;
		std::cout << std::endl;
		triang.print_info();

		try {
			RightTriangle rt;
			std::cout << std::endl;
			rt.print_info();
		}
		catch (bad_right_triangle err) {
			std::cout << err.what() << std::endl;
		}

		try {
			EquilateralTriangle et;
			std::cout << std::endl;
			et.print_info();
		}
		catch (bad_equilateral_triangle err) {
			std::cout << err.what() << std::endl;
		}
	}
	catch (bad_triangle err) {
		std::cout << err.what() << std::endl;
	}

	try {
		Tetragon tetrag;
		std::cout << std::endl;
		tetrag.print_info();

		try {
			Rectangle rect;
			std::cout << std::endl;
			rect.print_info();
		}
		catch (bad_rectangle_angle err) {
			std::cout << err.what() << std::endl;
		}
		catch (bad_rectangle_side_equality err) {
			std::cout << err.what() << std::endl;
		}

		try {
			Square squr;
			std::cout << std::endl;
			squr.print_info();
		}
		catch (bad_square_angle err) {
			std::cout << err.what() << std::endl;
		}
		catch (bad_square_side err) {
			std::cout << err.what() << std::endl;
		}

		try {
			Parallelogram par;
			std::cout << std::endl;
			par.print_info();
		}
		catch (bad_parallelogram_angle err) {
			std::cout << err.what() << std::endl;
		}
		catch (bad_parallelogram_side err) {
			std::cout << err.what() << std::endl;
		}

		try {
			Rhombus rhomb;
			std::cout << std::endl;
			rhomb.print_info();
		}
		catch (bad_rhombus_angle err) {
			std::cout << err.what() << std::endl;
		}
		catch (bad_rhombus_side err) {
			std::cout << err.what() << std::endl;
		}
	}
	catch (bad_tetragon_angle_sum err) {
		std::cout << err.what() << std::endl;
	}
	catch (bad_tetragon_side_count err) {
		std::cout << err.what() << std::endl;
	}
	
	

		

		

		

		

	
	
	return 0;
}