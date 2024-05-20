#include "cyllinder.h"
#define _USE_MATH_DEFINES
#include <cmath>

Cyllinder::Cyllinder(Point p1, double R, double H) : m_P1{p1}, m_R{R}, m_H{H}
{
}

double Cyllinder::get_volume() const
{
	return M_PI * m_R * m_R * m_H;
}

double Cyllinder::get_square() const
{
	return M_PI * m_R * m_R + 2 * m_R * m_H;
}

double Cyllinder::get_height() const
{
	return m_H;
}

double Cyllinder::get_radius() const
{
	return m_R;
}

std::tuple<Point> Cyllinder::get_points() const
{
	return { m_P1 };
}

void Cyllinder::set_points(std::tuple<Point> points)
{
	m_P1 = std::get<0>(points);
}

void Cyllinder::set_radius(double R)
{
	m_R = R;
}

void Cyllinder::set_height(double H)
{
	m_H = H;
}

void Cyllinder::shift(transform* tr, int x, int y, int z)
{
	tr->shiftCyllinder(x, y, z);
}

void Cyllinder::scaleX(transform* tr, int x)
{
	tr->scaleXCyllinder(x);
}

void Cyllinder::scaleY(transform* tr, int y)
{
	tr->scaleYCyllinder(y);
}

void Cyllinder::scaleZ(transform* tr, int z)
{
	tr->scaleZCyllinder(z);
}

void Cyllinder::scale(transform* tr, int s)
{
	tr->scaleCyllinder(s);
}
