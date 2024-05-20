#pragma once

#include "..\shape.h"
#include "..\transform.h"
#include <tuple>

class Circle : public Shape {
public:
	Circle(Point p1, double R);
public:
	virtual double get_volume() const override;
	virtual double get_square() const override;
	virtual double get_height() const override;
	virtual double get_radius() const override;

	std::tuple<Point> get_points() const;
	void set_points(std::tuple<Point> points);
	void set_radius(double R);

protected:
	virtual void shift(transform* tr, int x, int y, int z) override;
	virtual void scaleX(transform* tr, int x) override;
	virtual void scaleY(transform* tr, int y) override;
	virtual void scaleZ(transform* tr, int z) override;
	virtual void scale(transform* tr, int s) override;

private:
	Point m_P1;
	double m_R;

	friend transform;
	friend Circle;
};