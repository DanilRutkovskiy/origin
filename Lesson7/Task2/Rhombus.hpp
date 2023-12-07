#pragma once
#include "Tetragon.hpp"

class Rhombus : public Tetragon {
public:
	Rhombus();
	Rhombus(double side, double ang_ac, double ang_bd);
	~Rhombus() {};

public:
	virtual bool check_figure() const override;
};

