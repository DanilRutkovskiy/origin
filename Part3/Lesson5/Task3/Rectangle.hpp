#pragma once
#include "Tetragon.hpp"

class Rectangle : public Tetragon {
public:
	Rectangle() : Tetragon(2, 4, 2, 4, 90, 90, 90, 90, "Прямоугольник") {};
	Rectangle(double ac, double bd) : Tetragon(ac, bd, ac, bd, 90, 90, 90, 90, "Прямоугольник") {};
	~Rectangle() {};

public:
	virtual bool check_figure() const override;
};
