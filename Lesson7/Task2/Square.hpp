#pragma once
#include "Tetragon.hpp"

class Square : public Tetragon {
public:
	Square();
	Square(double side);
	~Square() {};

public:
	virtual bool check_figure() const override;
};

