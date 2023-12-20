#pragma once
#ifdef SHAPE_EXPORT
#define SHAPE_API _declspec(dllexport)
#else
#define SHAPE_API _declspec(dllimport)
#endif

class SHAPE_API Shape {
public:
	Shape() : m_edge_count{ 0 }, m_name{ "Фигура" } {};
	~Shape() {};

public:
	int get_edge_count() const { return m_edge_count; };
	std::string get_name() const { return m_name; };
	virtual void print_info() const;
	virtual bool check_figure() const;

protected:
	Shape(int edge, std::string name) : m_edge_count{ edge }, m_name{ name } {};

private:
	int m_edge_count;
	std::string m_name;
};