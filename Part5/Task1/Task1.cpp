#include <iostream>

struct point {
	double m_x;
	double m_y;
	point(double x, double y) {
		m_x = x;
		m_y = y;
	}

	point(int x, int y) {
		m_x = static_cast<double>(x);
		m_y = static_cast<double>(y);
	}
};

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: " 
		<< point_object.m_y << std::endl;
}

int main()
{
	for (int i = 0; i < 5; i++){
		point my_point{ i, 2 * i };
		print_point(my_point);
	}

	return 0;
}