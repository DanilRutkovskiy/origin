#pragma once
#include "Tetragon.hpp"

class Rectangle : public Tetragon {
public:
	Rectangle();
	Rectangle(double ac, double bd);
	~Rectangle() {};

public:
	virtual bool check_figure() const override;
};
