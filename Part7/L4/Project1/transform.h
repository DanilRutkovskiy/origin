#pragma once
#include"shape.h"
class Line;
class Square;
class Cube;
class Circle;
class Cyllinder;

class transform
{
public:
	transform(Shape* sh);
	Shape* shift(int x, int y, int z);
	Shape* scaleX(int a);
	Shape* scaleY(int d);
	Shape* scaleZ(int e);
	Shape* scale(int s);

protected:
	void shiftLine(int x, int y, int z);
	void scaleLine(int s);
	void scaleXLine(int x);
	void scaleYLine(int y);
	void scaleZLine(int z);

	void shiftSquare(int x, int y, int z);
	void scaleSquare(int s);
	void scaleXSquare(int x);
	void scaleYSquare(int y);
	void scaleZSquare(int z);

	void shiftCube(int x, int y, int z);
	void scaleCube(int s);
	void scaleXCube(int x);
	void scaleYCube(int y);
	void scaleZCube(int z);

	void shiftCircle(int x, int y, int z);
	void scaleCircle(int s);
	void scaleXCircle(int x);
	void scaleYCircle(int y);
	void scaleZCircle(int z);

	void shiftCyllinder(int x, int y, int z);
	void scaleCyllinder(int s);
	void scaleXCyllinder(int x);
	void scaleYCyllinder(int y);
	void scaleZCyllinder(int z);

private:
	Shape* m_Shape;

	friend Line;
	friend Square;
	friend Cube;
	friend Circle;
	friend Cyllinder;
};

