#pragma once

#include "..\shape.h"
#include "..\transform.h"
#include <tuple>

class Cube : public Shape {
public:
	Cube(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8);
public:
	virtual double get_volume() const override;
	virtual double get_square() const override;
	virtual double get_height() const override;
	virtual double get_radius() const override;

	std::tuple<Point, Point, Point, Point, Point, Point, Point, Point> get_points() const;
	void set_points(std::tuple<Point, Point, Point, Point, Point, Point, Point, Point> points);

protected:
	virtual void shift(transform* tr, int x, int y, int z) override;
	virtual void scaleX(transform* tr, int x) override;
	virtual void scaleY(transform* tr, int y) override;
	virtual void scaleZ(transform* tr, int z) override;
	virtual void scale(transform* tr, int s) override;

private:
	Point m_P1;
	Point m_P2;
	Point m_P3;
	Point m_P4;
	Point m_P5;
	Point m_P6;
	Point m_P7;
	Point m_P8;

	friend transform;
};