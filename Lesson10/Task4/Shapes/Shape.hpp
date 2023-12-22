#pragma once
#ifdef SHAPE_EXPORTS
#define SHAPE_API _declspec(dllexport)
#define EXT
#else
#define SHAPE_API _declspec(dllimport)
#define EXT extern
#endif

class SHAPE_API Shape {
public:
	Shape() : m_edge_count{ 0 }, m_name{ "Фигура" } {};
	~Shape() {};

public:
	int get_edge_count() const;
	const char* get_name() const;
	virtual void print_info() const;
	virtual bool check_figure() const;

protected:
	Shape(int edge, const char* name) : m_edge_count{ edge }, m_name{ name } {};

private:
	int m_edge_count;
	const char* m_name;
};