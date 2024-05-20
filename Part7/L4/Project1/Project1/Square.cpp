#include "..\..\Square.h"
#include <math.h>

Square::Square(Point p1, Point p2, Point p3, Point p4) : m_P1{ p1 }, m_P2{ p2 }, m_P3{ p3 }, m_P4{ p4 }
{
}

double Square::get_volume() const
{
	return 0.0;
}

double Square::get_square() const
{
	int a = abs(m_P1.x - m_P3.x);
	int b = abs(m_P1.y - m_P3.y);

	return a * b;
}

double Square::get_height() const
{
	return 0.0;
}

double Square::get_radius() const
{
	return 0.0;
}

std::tuple<Point, Point, Point, Point> Square::get_points() const
{
	return {m_P1, m_P2, m_P3, m_P4};
}

void Square::set_points(std::tuple<Point, Point, Point, Point> points)
{
	m_P1 = std::get<0>(points);
	m_P2 = std::get<1>(points);
	m_P3 = std::get<2>(points);
	m_P4 = std::get<3>(points);
}

void Square::shift(transform* tr, int x, int y, int z)
{
	tr->shiftSquare(x, y, z);
}

void Square::scaleX(transform* tr, int x)
{
	tr->scaleXSquare(x);
}

void Square::scaleY(transform* tr, int y)
{
	tr->scaleYSquare(y);
}

void Square::scaleZ(transform* tr, int z)
{
	tr->scaleZSquare(z);
}

void Square::scale(transform* tr, int s)
{
	tr->scaleSquare(s);
}