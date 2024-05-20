#pragma once
class transform;

struct Point {
	int x = 0;
	int y = 0;
	int z = 0;
};

class Shape
{
public:
	virtual double get_volume() const = 0;
	virtual double get_square() const = 0;
	virtual double get_height() const = 0;
	virtual double get_radius() const = 0;

protected:
	Shape() = default;

protected:
	virtual void shift(transform* tr, int x, int y, int z) = 0;
	virtual void scaleX(transform* tr, int x) = 0;
	virtual void scaleY(transform* tr, int y) = 0;
	virtual void scaleZ(transform* tr, int z) = 0;
	virtual void scale(transform* tr, int s) = 0;

	friend transform;
};
