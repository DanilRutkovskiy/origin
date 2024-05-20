#include "transform.h"
#include "..\..\line.h"
#include "..\..\Square.h"
#include "..\..\Cube.h"
#include "..\..\Circle.h"
#include "..\..\cyllinder.h"

transform::transform(Shape* sh)
{
	m_Shape = sh;
}

Shape* transform::shift(int m, int n, int k)
{
	m_Shape->shift(this, m, n, k);
	return m_Shape;
}

Shape* transform::scaleX(int a)
{
	m_Shape->scaleX(this, a);
	return m_Shape;
}

Shape* transform::scaleY(int d)
{
	m_Shape->scaleY(this, d);
	return m_Shape;
}

Shape* transform::scaleZ(int e)
{
	m_Shape->scaleZ(this, e);
	return m_Shape;
}

Shape* transform::scale(int s)
{
	m_Shape->scale(this, s);
	return m_Shape;
}

void transform::shiftLine(int x, int y, int z)
{
	auto line = dynamic_cast<Line*>(m_Shape);

	auto points = line->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);

	p1.x += x; p1.y += y;
	p2.x += x; p2.y += y;

	line->set_points({ p1, p2 });
}

void transform::scaleLine(int s)
{
	auto line = dynamic_cast<Line*>(m_Shape);

	auto points = line->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);

	p1.x /= s;
	p2.x /= s;

	line->set_points({ p1, p2 });
}

void transform::scaleXLine(int x)
{
	auto line = dynamic_cast<Line*>(m_Shape);

	auto points = line->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);

	p1.x *= x;
	p2.x *= x;

	line->set_points({ p1, p2 });
}

void transform::scaleYLine(int y)
{
	auto line = dynamic_cast<Line*>(m_Shape);

	auto points = line->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);

	p1.y *= y;
	p2.y *= y;

	line->set_points({ p1, p2 });
}

void transform::scaleZLine(int z)
{
	return;
}

void transform::shiftSquare(int x, int y, int z)
{
	auto square = dynamic_cast<Square*>(m_Shape);

	auto points = square->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);

	p1.x += x; p1.y += y;
	p2.x += x; p2.y += y;
	p3.x += x; p3.y += y;
	p4.x += x; p4.y += y;

	square->set_points({ p1, p2, p3, p4});
}

void transform::scaleSquare(int s)
{
	auto square = dynamic_cast<Square*>(m_Shape);

	auto points = square->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);

	p1.x /= s; p1.y /= s;
	p2.x /= s; p2.y /= s;
	p3.x /= s; p3.y /= s;
	p4.x /= s; p4.y /= s;

	square->set_points({ p1, p2, p3, p4 });
}

void transform::scaleXSquare(int x)
{
	auto square = dynamic_cast<Square*>(m_Shape);

	auto points = square->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);

	p1.x *= x;
	p2.x *= x;
	p3.x *= x;
	p4.x *= x;

	square->set_points({ p1, p2, p3, p4 });
}

void transform::scaleYSquare(int y)
{
	auto square = dynamic_cast<Square*>(m_Shape);

	auto points = square->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);

	p1.y *= y;
	p2.y *= y;
	p3.y *= y;
	p4.y *= y;

	square->set_points({ p1, p2, p3, p4 });
}

void transform::scaleZSquare(int z)
{
	return;
}

void transform::shiftCube(int x, int y, int z)
{
	auto cube = dynamic_cast<Cube*>(m_Shape);

	auto points = cube->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);
	Point p5 = std::get<4>(points);
	Point p6 = std::get<5>(points);
	Point p7 = std::get<6>(points);
	Point p8 = std::get<7>(points);

	p1.x += x; p1.y += y; p1.z += z;
	p2.x += x; p2.y += y; p1.z += z;
	p3.x += x; p1.y += y; p1.z += z;
	p4.x += x; p1.y += y; p1.z += z;
	p5.x += x; p1.y += y; p1.z += z;
	p6.x += x; p1.y += y; p1.z += z;
	p7.x += x; p1.y += y; p1.z += z;
	p8.x += x; p1.y += y; p1.z += z;

	cube->set_points({ p1, p2, p3, p4, p5 ,p6, p7, p8 });
}

void transform::scaleCube(int s)
{
	auto cube = dynamic_cast<Cube*>(m_Shape);

	auto points = cube->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);
	Point p5 = std::get<4>(points);
	Point p6 = std::get<5>(points);
	Point p7 = std::get<6>(points);
	Point p8 = std::get<7>(points);

	p1.x /= s; p1.y /= s; p1.z /= s;
	p2.x /= s; p2.y /= s; p1.z /= s;
	p3.x /= s; p1.y /= s; p1.z /= s;
	p4.x /= s; p1.y /= s; p1.z /= s;
	p5.x /= s; p1.y /= s; p1.z /= s;
	p6.x /= s; p1.y /= s; p1.z /= s;
	p7.x /= s; p1.y /= s; p1.z /= s;
	p8.x /= s; p1.y /= s; p1.z /= s;

	cube->set_points({ p1, p2, p3, p4, p5 ,p6, p7, p8 });
}

void transform::scaleXCube(int x)
{
	auto cube = dynamic_cast<Cube*>(m_Shape);

	auto points = cube->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);
	Point p5 = std::get<4>(points);
	Point p6 = std::get<5>(points);
	Point p7 = std::get<6>(points);
	Point p8 = std::get<7>(points);

	p1.x *= x;
	p2.x *= x;
	p3.x *= x;
	p4.x *= x;
	p5.x *= x;
	p6.x *= x;
	p7.x *= x;
	p8.x *= x;

	cube->set_points({ p1, p2, p3, p4, p5 ,p6, p7, p8 });
}

void transform::scaleYCube(int y)
{
	auto cube = dynamic_cast<Cube*>(m_Shape);

	auto points = cube->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);
	Point p5 = std::get<4>(points);
	Point p6 = std::get<5>(points);
	Point p7 = std::get<6>(points);
	Point p8 = std::get<7>(points);

	p1.y *= y;
	p2.y *= y;
	p1.y *= y;
	p1.y *= y;
	p1.y *= y;
	p1.y *= y;
	p1.y *= y;
	p1.y *= y;

	cube->set_points({ p1, p2, p3, p4, p5 ,p6, p7, p8 });
}

void transform::scaleZCube(int z)
{
	auto cube = dynamic_cast<Cube*>(m_Shape);

	auto points = cube->get_points();

	Point p1 = std::get<0>(points);
	Point p2 = std::get<1>(points);
	Point p3 = std::get<2>(points);
	Point p4 = std::get<3>(points);
	Point p5 = std::get<4>(points);
	Point p6 = std::get<5>(points);
	Point p7 = std::get<6>(points);
	Point p8 = std::get<7>(points);

	p1.z *= z;
	p1.z *= z;
	p1.z *= z;
	p1.z *= z;
	p1.z *= z;
	p1.z *= z;
	p1.z *= z;
	p1.z *= z;

	cube->set_points({ p1, p2, p3, p4, p5 ,p6, p7, p8 });
}

void transform::shiftCircle(int x, int y, int z)
{
	auto circle = dynamic_cast<Circle*>(m_Shape);

	auto points = circle->get_points();

	Point p1 = std::get<0>(points);

	p1.x += x; p1.y += y;

	circle->set_points({ p1 });
}

void transform::scaleCircle(int s)
{
	auto circle = dynamic_cast<Circle*>(m_Shape);

	double R = circle->get_radius();

	R /= s;

	circle->set_radius(R);
}

void transform::scaleXCircle(int x)
{
}

void transform::scaleYCircle(int y)
{
}

void transform::scaleZCircle(int z)
{
}

void transform::shiftCyllinder(int x, int y, int z)
{
}

void transform::scaleCyllinder(int s)
{
}

void transform::scaleXCyllinder(int x)
{
}

void transform::scaleYCyllinder(int y)
{
}

void transform::scaleZCyllinder(int z)
{
}
