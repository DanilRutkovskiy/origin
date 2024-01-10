#pragma once
#include "Tetragon.hpp"

class Parallelogram : public Tetragon {
public:
	Parallelogram() : Tetragon(2, 4, 2, 4, 60, 120, 60, 120, "ֿאנאככוכמדנאלל") {};
	Parallelogram(double ac, double bd, double ang_ac, double ang_bd) : Tetragon(ac, bd, ac, bd, ang_ac, ang_bd, ang_ac, ang_bd, "ֿאנאככוכמדנאלל") {};
	~Parallelogram() {};

public:
	virtual bool check_figure() const override;
};
