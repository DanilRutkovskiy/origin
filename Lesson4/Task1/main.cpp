#include <iostream>

class Shape {
public:
	Shape() : m_edge_count{ 0 }, m_name{"Фигура"} {};
	~Shape() {};

public:
	int get_edge_count() { return m_edge_count; };
	std::string get_name() { return m_name; };

protected:
	Shape(int edge, std::string name) : m_edge_count{ edge }, m_name {name} {};

private:
	int m_edge_count;
	std::string m_name;
};

class Triangle : public Shape {
public:
	Triangle() : Shape{ 3, "Треугольник"} {};
	~Triangle() {};
};

class Tetragon : public Shape {
public:
	Tetragon() : Shape{4, "Четырёхугольник"} {};
	~Tetragon() {};
};

int main() {
	setlocale(LC_ALL, "Russian");
	Shape sh;
	Triangle triang;
	Tetragon tetr;
	std::cout << "Количество сторон: " << std::endl;
	std::cout << sh.get_name() << ": " << sh.get_edge_count() << std::endl;
	std::cout << triang.get_name() << ": " << triang.get_edge_count() << std::endl;
	std::cout << tetr.get_name() << ": " << tetr.get_edge_count() << std::endl;
	return 0;
}