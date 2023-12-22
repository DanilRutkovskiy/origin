#pragma once
#include "Tetragon.hpp"

class Parallelogram : public Tetragon {
public:
	Parallelogram();
	Parallelogram(double ac, double bd, double ang_ac, double ang_bd);
	~Parallelogram();

public:
	virtual bool check_figure() const override;
};
