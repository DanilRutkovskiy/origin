#pragma once
#include <string>
#include "MyExceptions.hpp"

class Shape {
public:
	Shape();
	~Shape() {};

public:
	int get_edge_count() const { return m_edge_count; };
	std::string get_name() const { return m_name; };
	virtual void print_info() const;
	virtual bool check_figure() const;

protected:
	Shape(int edge, std::string name);

private:
	int m_edge_count;
	std::string m_name;
};