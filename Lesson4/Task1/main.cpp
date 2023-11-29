#include <iostream>

class Shape {
public:
	Shape() : m_edge_count{0} {};
	~Shape() {};

public:
	int get_edge_count() { return m_edge_count; };
	std::string get_name() const { return m_name; } ;
	virtual void print_info() const = 0;

protected:
	Shape(int edge, std::string name) : m_edge_count{ edge }, m_name{ name } {};

private:
	int m_edge_count;
	std::string m_name;
};

class Triangle : public Shape {
public:
	Triangle() : Shape{ 3, "Треугольник"}, m_a{1}, m_b{2}, m_c{3}, m_A{20}, m_B{60}, m_C{100}{};
	Triangle(double a, double b, double c, double A, double B, double C) : 
		Shape{ 3, "Треугольник" }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C } {};
	~Triangle() {};

protected:
	Triangle(double a, double b, double c, double A, double B, double C, std::string name) :
		Shape{ 3, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C } {};
public:
	virtual void print_info() const override;

private:
	double m_a, m_b, m_c;//Стороны
	double m_A, m_B, m_C;//Углы
};

void Triangle::print_info() const {
	std::cout << get_name() << ":" << std::endl;
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << std::endl;
}

class RightTriangle : public Triangle {
public:
	RightTriangle() : Triangle(1, 2, 3, 45, 45, 90, "Прямоугольный треугольник") {};
	RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник" ) {};
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle() : Triangle(1, 1, 1, 60, 60, 60, "Равносторонний треугольник") {};
	EquilateralTriangle(double side, double angle) : Triangle(side, side, side, angle, angle, angle, "Равносторонний треугольник") {};
};

class Tetragon : public Shape {
public:
	Tetragon() : Shape{ 4, "Четырёхугольник"}, m_a{3}, m_b{3}, m_c{3}, m_d{3}, m_A{60}, m_B{80}, m_C{60}, m_D{40} {};
	Tetragon(double a, double b, double c, double d, double A, double B, double C, double D) :
		Shape{ 4, "Четырёхугольник"}, m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_A{ A }, m_B{ B }, m_C{ C }, m_D{ D } {};
	~Tetragon() {};

protected:
	Tetragon(double a, double b, double c, double d, double A, double B, double C, double D, std::string name) :
		Shape{ 4, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_A{ A }, m_B{ B }, m_C{ C }, m_D{ D } {};

public:
	virtual void print_info() const override;

private:
	double m_a, m_b, m_c, m_d;//Стороны
	double m_A, m_B, m_C, m_D;//Углы
};

void Tetragon::print_info() const {
	std::cout << get_name() << ":" << std::endl;
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << " ,d=" << m_d << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << " ,D=" << m_D << std::endl;
}

class Rectangle : public Tetragon {
public:
	Rectangle() : Tetragon(2, 4, 2, 4, 90, 90, 90, 90, "Прямоугольник") {};
	Rectangle(double ac, double bd) : Tetragon(ac, bd, ac, bd, 90, 90, 90, 90, "Прямоугольник") {};
	~Rectangle() {};
};

class Square : public Tetragon {
public:
	Square() : Tetragon(4, 4, 4, 4, 90, 90, 90, 90, "Квадрат") {};
	Square(double side) : Tetragon(side, side, side, side, 90, 90, 90, 90, "Квадрат") {};
	~Square() {};
};

class Parallelogram : public Tetragon {
public:
	Parallelogram() : Tetragon(2, 4, 2, 4, 60, 120, 60, 120, "Параллелограмм") {};
	Parallelogram(double ac, double bd, double ang_ac, double ang_bd) : Tetragon(ac, bd, ac, bd, ang_ac, ang_bd, ang_ac, ang_bd, "Параллелограмм") {};
	~Parallelogram() {};
};

class Rhombus : public Tetragon {
public:
	Rhombus() : Tetragon(4, 4, 4, 4, 60, 120, 60, 120, "Ромб") {};
	Rhombus(double side, double ang_ac, double ang_bd) : Tetragon(side, side, side, side, ang_ac, ang_bd, ang_ac, ang_bd, "Параллелограмм") {};
	~Rhombus() {};
};

void print_info(const Shape* sh) {
	sh->print_info();
}

int main() {
	setlocale(LC_ALL, "Russian");

	Triangle triang;
	print_info(&triang);
	std::cout << std::endl;

	RightTriangle rt;
	print_info(&rt);
	std::cout << std::endl;

	EquilateralTriangle et;
	print_info(&et);
	std::cout << std::endl;

	Tetragon tetrag;
	print_info(&tetrag);
	std::cout << std::endl;

	Rectangle rect;
	print_info(&rect);
	std::cout << std::endl;

	Square squr;
	print_info(&squr);
	std::cout << std::endl;

	Parallelogram par;
	print_info(&par);
	std::cout << std::endl;

	Rhombus rhomb;
	print_info(&rhomb);
	std::cout << std::endl;

	return 0;
}