#include <iostream>

class Shape {
public:
	Shape() : m_edge{0} {};
	~Shape() {};

public:
	int get_edge_count() { return m_edge; };

protected:
	int m_edge;
};

class Triangle : public Shape {
public:
	Triangle() { m_edge = 3; };
	~Triangle() {};
};

class Tetragon : public Shape {
public:
	Tetragon() { m_edge = 4; };
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