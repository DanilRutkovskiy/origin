#include <iostream>

class Shape {
public:
	Shape() : m_edge_count{0} {};
	~Shape() {};

public:
	int get_edge_count() { return m_edge_count; };

protected:
	Shape(int edge) : m_edge_count{ edge } {};

private:
	int m_edge_count;
};

class Triangle : public Shape {
public:
	Triangle() : Shape{ 3 } {};
	~Triangle() {};
};

class Tetragon : public Shape {
public:
	Tetragon() : Shape{4} {};
	~Tetragon() {};
};

int main() {
	setlocale(LC_ALL, "Russian");
	Shape sh;
	Triangle triang;
	Tetragon tetr;
	std::cout << "���������� ������: " << std::endl;
	std::cout << "������: " << sh.get_edge_count() << std::endl;
	std::cout << "�����������: " << triang.get_edge_count() << std::endl;
	std::cout << "��������������: " << tetr.get_edge_count() << std::endl;
	return 0;
}