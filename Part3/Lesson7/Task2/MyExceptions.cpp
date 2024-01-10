#include "MyExceptions.hpp"

const char* bad_triangle::what() const noexcept {
	return "Ошибка создания треугольника.\0";
}

const char* bad_triangle_angle_sum::what() const noexcept {
	return "Сумма углов треугольника не равна 180 градусам\0";
}

const char* bad_triangle_side_count::what() const noexcept {
	return "Количество сторон треугольника не равно 3\0";
}

const char* bad_right_triangle::what() const noexcept {
	return "Ни один из углов треугольника не равен 90 градусов\0";
}

const char* bad_equilateral_triangle::what() const noexcept {
	return "Треугольник с данными параметрами не является равносторонним\0";
}

const char* bad_tetragon::what() const noexcept {
	return "Невозможно создать четырёхугольник с заданными параметрами\0";
}

const char* bad_tetragon_angle_sum::what() const noexcept
{
	return "Невозможно создать четырёхугольни. Сумма углов не равна 360 градусов\0";
}

const char* bad_tetragon_side_count::what() const noexcept
{
	return "Невозможно создать четырёхугольни. Количество сторон не равно 4\0";
}

const char* bad_rectangle_side_equality::what() const noexcept
{
	return "Невозможно создать прямоугольник. Стороны не равны попарно\0";
}

const char* bad_rectangle_angle::what() const noexcept
{
	return "Невозможно создать прямоугольник. Углы не равны 90 градусов\0";
}

const char* bad_square_side::what() const noexcept
{
	return "Невозможно создать квадрат. Стороны не равны\0";
}

const char* bad_square_angle::what() const noexcept
{
	return "Невозможно создать квадрат. Углы не равны\0";
}

const char* bad_parallelogram_angle::what() const noexcept
{
	return "Невозможно создать параллелограмм. Углы попарно не равны\0";
}

const char* bad_parallelogram_side::what() const noexcept
{
	return "Невозможно создать параллелограмм. Стороны попарно не равны\0";
}

const char* bad_rhombus_side::what() const noexcept
{
	return "Невозможно создать ромб. Стороны не равны\0";
}

const char* bad_rhombus_angle::what() const noexcept
{
	return "Невозможно создать ромб. Углы попарно не равны\0";
}