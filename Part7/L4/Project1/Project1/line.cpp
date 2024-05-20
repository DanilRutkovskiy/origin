#include "line.h"

Line::Line(Point _p1, Point _p2) : m_P1{ _p1 }, m_P2{ _p2 } {

}

double Line::get_volume() const
{
	return 0.0;
}

double Line::get_square() const
{
	return 0.0;
}

double Line::get_height() const
{
	return 0.0;
}

double Line::get_radius() const
{
	return 0.0;
}

std::tuple<Point, Point> Line::get_points() const
{
	return { m_P1, m_P2 };
}

void Line::set_points(std::tuple<Point, Point> points)
{
	m_P1 = std::get<0>(points);
	m_P2 = std::get<1>(points);
}

void Line::shift(transform* tr, int x, int y, int z)
{	
	tr->shiftLine(x, y, z);
}

void Line::scaleX(transform* tr, int x)
{
	tr->scaleXLine(x);
}

void Line::scaleY(transform* tr, int y)
{
	tr->scaleYLine(y);
}

void Line::scaleZ(transform* tr, int z)
{
	tr->scaleZLine(z);
}

void Line::scale(transform* tr, int s)
{
	tr->scaleLine(s);
}