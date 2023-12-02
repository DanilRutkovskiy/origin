#include <iostream>

class Shape {
public:
	Shape() : m_edge_count{ 0 }, m_name{"Фигура"} {};
	~Shape() {};

public:
	int get_edge_count() const { return m_edge_count; };
	std::string get_name() const { return m_name; } ;
	virtual void print_info() const;
	virtual bool check_figure() const;

protected:
	Shape(int edge, std::string name) : m_edge_count{ edge }, m_name{ name } {};

private:
	int m_edge_count;
	std::string m_name;
};

bool Shape::check_figure() const {
	return m_edge_count == 0;
}

void Shape::print_info() const {
	std::cout << get_name() << ":" << std::endl;
	std::cout << (check_figure() ? "Правильная" : "Неправильная") << std::endl;
	std::cout << "Количество сторон: " << m_edge_count << std::endl;
}

class Triangle : public Shape {
public:
	Triangle() : Shape{ 3, "Треугольник"}, m_a{1}, m_b{2}, m_c{3}, m_A{20}, m_B{60}, m_C{100}{};
	Triangle(double a, double b, double c, double A, double B, double C) : 
		Shape{ 3, "Треугольник" }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C } {};
	~Triangle() {};

public:
	virtual void print_info() const override;
	virtual bool check_figure() const override;

	virtual double get_a() const { return m_a; };
	virtual double get_b() const { return m_b; };
	virtual double get_c() const { return m_c; };

	virtual double get_A() const { return m_A; };
	virtual double get_B() const { return m_B; };
	virtual double get_C() const { return m_C; };

protected:
	Triangle(double a, double b, double c, double A, double B, double C, std::string name) :
		Shape{ 3, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_A{ A }, m_B{ B }, m_C{ C } {};

private:
	double m_a, m_b, m_c;//Стороны
	double m_A, m_B, m_C;//Углы
};

bool Triangle::check_figure() const {
	return (get_edge_count() == 3) && ((m_A + m_B + m_C) == 180);
}

void Triangle::print_info() const {
	Shape::print_info();
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << std::endl;
}

class RightTriangle : public Triangle {
public:
	RightTriangle() : Triangle(1, 2, 3, 45, 45, 90, "Прямоугольный треугольник") {};
	RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник" ) {};
public:
	virtual bool check_figure() const override;
};

bool RightTriangle::check_figure() const {
	return Triangle::check_figure() && (get_C() == 90);
}

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle() : Triangle(1, 1, 1, 60, 60, 60, "Равносторонний треугольник") {};
	EquilateralTriangle(double side, double angle) : Triangle(side, side, side, angle, angle, angle, "Равносторонний треугольник") {};
public:
	virtual bool check_figure() const override;
};

bool EquilateralTriangle::check_figure() const {
	return Triangle::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_A() == 60 && get_B() == 60 && get_C() == 60);
}

class Tetragon : public Shape {
public:
	Tetragon() : Shape{ 4, "Четырёхугольник"}, m_a{3}, m_b{3}, m_c{3}, m_d{3}, m_A{60}, m_B{80}, m_C{60}, m_D{40} {};
	Tetragon(double a, double b, double c, double d, double A, double B, double C, double D) :
		Shape{ 4, "Четырёхугольник"}, m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_A{ A }, m_B{ B }, m_C{ C }, m_D{ D } {};
	~Tetragon() {};

public:
	virtual bool check_figure() const override;
	virtual void print_info() const override;

	virtual double get_a() const { return m_a; };
	virtual double get_b() const { return m_b; };
	virtual double get_c() const { return m_c; };
	virtual double get_d() const { return m_d; };

	virtual double get_A() const { return m_A; };
	virtual double get_B() const { return m_B; };
	virtual double get_C() const { return m_C; };
	virtual double get_D() const { return m_D; };

protected:
	Tetragon(double a, double b, double c, double d, double A, double B, double C, double D, std::string name) :
		Shape{ 4, name }, m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_A{ A }, m_B{ B }, m_C{ C }, m_D{ D } {};



private:
	double m_a, m_b, m_c, m_d;//Стороны
	double m_A, m_B, m_C, m_D;//Углы
};

bool Tetragon::check_figure() const {
	return get_edge_count() == 4 && (get_A() + get_B() + get_C() + get_D()) == 360;
}

void Tetragon::print_info() const {
	Shape::print_info();
	std::cout << "Стороны: " << "a=" << m_a << " ,b=" << m_b << " ,c=" << m_c << " ,d=" << m_d << std::endl;
	std::cout << "Углы: " << "A=" << m_A << " ,B=" << m_B << " ,C=" << m_C << " ,D=" << m_D << std::endl;
}

class Rectangle : public Tetragon {
public:
	Rectangle() : Tetragon(2, 4, 2, 4, 90, 90, 90, 90, "Прямоугольник") {};
	Rectangle(double ac, double bd) : Tetragon(ac, bd, ac, bd, 90, 90, 90, 90, "Прямоугольник") {};
	~Rectangle() {};

public:
	virtual bool check_figure() const override;
};

bool Rectangle::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_c()) && (get_b() == get_d()) &&
		(get_A() == 90) && (get_B() == 90) && (get_C() == 90) && (get_D() == 90);
}

class Square : public Tetragon {
public:
	Square() : Tetragon(4, 4, 4, 4, 90, 90, 90, 90, "Квадрат") {};
	Square(double side) : Tetragon(side, side, side, side, 90, 90, 90, 90, "Квадрат") {};
	~Square() {};

public:
	virtual bool check_figure() const override;
};

bool Square::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_c() == get_d()) &&
		(get_A() == 90) && (get_B() == 90) && (get_C() == 90) && (get_D() == 90);
}

class Parallelogram : public Tetragon {
public:
	Parallelogram() : Tetragon(2, 4, 2, 4, 60, 120, 60, 120, "Параллелограмм") {};
	Parallelogram(double ac, double bd, double ang_ac, double ang_bd) : Tetragon(ac, bd, ac, bd, ang_ac, ang_bd, ang_ac, ang_bd, "Параллелограмм") {};
	~Parallelogram() {};

public:
	virtual bool check_figure() const override;
};

bool Parallelogram::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_c()) && (get_b() == get_d()) &&
		(get_A() == get_C()) && (get_B() == get_D());
}

class Rhombus : public Tetragon {
public:
	Rhombus() : Tetragon(4, 4, 4, 4, 60, 120, 60, 120, "Ромб") {};
	Rhombus(double side, double ang_ac, double ang_bd) : Tetragon(side, side, side, side, ang_ac, ang_bd, ang_ac, ang_bd, "Параллелограмм") {};
	~Rhombus() {};

public:
	virtual bool check_figure() const override;
};

bool Rhombus::check_figure() const {
	return Tetragon::check_figure() && (get_a() == get_b()) && (get_b() == get_c()) && (get_c() == get_d()) &&
		(get_A() == get_C()) && (get_B() == get_D());
}

int main() {
	setlocale(LC_ALL, "Russian");

	Triangle triang;
	std::cout << std::endl;
	triang.print_info();

	RightTriangle rt;
	std::cout << std::endl;
	rt.print_info();

	EquilateralTriangle et;
	std::cout << std::endl;
	et.print_info();

	Tetragon tetrag;
	std::cout << std::endl;
	tetrag.print_info();

	Rectangle rect;
	std::cout << std::endl;
	rect.print_info();

	Square squr;
	std::cout << std::endl;
	squr.print_info();

	Parallelogram par;
	std::cout << std::endl;
	par.print_info();

	Rhombus rhomb;
	std::cout << std::endl;
	rhomb.print_info();
	return 0;
}