#pragma once
#include "Tetragon.hpp"

class Rhombus : public Tetragon {
public:
	Rhombus() : Tetragon(4, 4, 4, 4, 60, 120, 60, 120, "����") {};
	Rhombus(double side, double ang_ac, double ang_bd) : Tetragon(side, side, side, side, ang_ac, ang_bd, ang_ac, ang_bd, "����") {};
	~Rhombus() {};

public:
	virtual bool check_figure() const override;
};

