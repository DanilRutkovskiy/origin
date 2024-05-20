#include "cube.h"
#include <math.h>

Cube::Cube(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8)
	: m_P1{p1}, m_P2{ p2 }, m_P3{ p3 }, m_P4{ p4 }, m_P5{ p5 }, m_P6{ p6 }, m_P7{ p7 }, m_P8{ p8 }
{

}

double Cube::get_volume() const
{
	int a = abs(m_P1.x - m_P7.x);
	int b = abs(m_P1.y - m_P7.y);
	int c = abs(m_P1.z - m_P7.z);
	return a * b * c;
}

double Cube::get_square() const
{
	int a = abs(m_P1.x - m_P7.x);
	int b = abs(m_P1.y - m_P7.y);
	int c = abs(m_P1.z - m_P7.z);
	return 2 * a * b + 2 * a * c + 2 * b * c;
}

double Cube::get_height() const
{
	return 0.0;
}

double Cube::get_radius() const
{
	return 0.0;
}

std::tuple<Point, Point, Point, Point, Point, Point, Point, Point> Cube::get_points() const
{
	return { m_P1, m_P2, m_P3, m_P4, m_P5, m_P6, m_P7, m_P8 };
}

void Cube::set_points(std::tuple<Point, Point, Point, Point, Point, Point, Point, Point> points)
{
	m_P1 = std::get<0>(points);
	m_P2 = std::get<1>(points);
	m_P3 = std::get<2>(points);
	m_P4 = std::get<3>(points);
	m_P5 = std::get<4>(points);
	m_P6 = std::get<5>(points);
	m_P7 = std::get<6>(points);
	m_P8 = std::get<7>(points);
}

void Cube::shift(transform* tr, int x, int y, int z)
{
	tr->shiftCube(x, y, z);
}

void Cube::scaleX(transform* tr, int x)
{
	tr->scaleXCube(x);
}

void Cube::scaleY(transform* tr, int y)
{
	tr->scaleYCube(y);
}

void Cube::scaleZ(transform* tr, int z)
{
	tr->scaleZCube(z);
}

void Cube::scale(transform* tr, int s)
{
	tr->scaleCube(s);
}