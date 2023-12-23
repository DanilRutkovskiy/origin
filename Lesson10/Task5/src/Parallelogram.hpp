#pragma once
#include "Tetragon.hpp"

class SHAPE_API Parallelogram : public Tetragon {
public:
	Parallelogram();
	Parallelogram(double ac, double bd, double ang_ac, double ang_bd);
	~Parallelogram();

public:
	virtual bool check_figure() const override;
};
