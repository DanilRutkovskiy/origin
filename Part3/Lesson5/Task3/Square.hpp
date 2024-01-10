#pragma once
#include "Tetragon.hpp"

class Square : public Tetragon {
public:
	Square() : Tetragon(4, 4, 4, 4, 90, 90, 90, 90, " вадрат") {};
	Square(double side) : Tetragon(side, side, side, side, 90, 90, 90, 90, " вадрат") {};
	~Square() {};

public:
	virtual bool check_figure() const override;
};

