#include "circle.h"
#define _USE_MATH_DEFINES
#include <cmath>


Circle::Circle(Point p1, double R) : m_P1{p1}, m_R{R}
{
}

double Circle::get_volume() const
{
	return 0.0;
}

double Circle::get_square() const
{
	return M_PI * m_R * m_R;
}

double Circle::get_height() const
{
	return 0.0;
}

double Circle::get_radius() const
{
	return m_R;
}

std::tuple<Point> Circle::get_points() const
{
	return { m_P1 };
}

void Circle::set_points(std::tuple<Point> points)
{
	m_P1 = std::get<0>(points);
}

void Circle::set_radius(double R)
{
	m_R = R;
}

void Circle::shift(transform* tr, int x, int y, int z)
{
	tr->shiftCircle(x, y, z);
}

void Circle::scaleX(transform* tr, int x)
{
	tr->scaleXCircle(x);
}

void Circle::scaleY(transform* tr, int y)
{
	tr->scaleYCircle(y);
}

void Circle::scaleZ(transform* tr, int z)
{
	tr->scaleZCircle(z);
}

void Circle::scale(transform* tr, int s)
{
	tr->scaleCircle(s);
}