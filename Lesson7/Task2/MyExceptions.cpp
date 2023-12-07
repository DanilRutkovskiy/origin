#include "MyExceptions.hpp"

const char* bad_triangle::what() const noexcept {
	return "������ �������� ������������.\0";
}

const char* bad_triangle_angle_sum::what() const noexcept {
	return "����� ����� ������������ �� ����� 180 ��������\0";
}

const char* bad_triangle_side_count::what() const noexcept {
	return "���������� ������ ������������ �� ����� 3\0";
}

const char* bad_right_triangle::what() const noexcept {
	return "�� ���� �� ����� ������������ �� ����� 90 ��������\0";
}

const char* bad_equilateral_triangle::what() const noexcept {
	return "����������� � ������� ����������� �� �������� ��������������\0";
}

const char* bad_tetragon::what() const noexcept {
	return "���������� ������� �������������� � ��������� �����������\0";
}

const char* bad_tetragon_angle_sum::what() const noexcept
{
	return "���������� ������� �������������. ����� ����� �� ����� 360 ��������\0";
}

const char* bad_tetragon_side_count::what() const noexcept
{
	return "���������� ������� �������������. ���������� ������ �� ����� 4\0";
}

const char* bad_rectangle_side_equality::what() const noexcept
{
	return "���������� ������� �������������. ������� �� ����� �������\0";
}

const char* bad_rectangle_angle::what() const noexcept
{
	return "���������� ������� �������������. ���� �� ����� 90 ��������\0";
}

const char* bad_square_side::what() const noexcept
{
	return "���������� ������� �������. ������� �� �����\0";
}

const char* bad_square_angle::what() const noexcept
{
	return "���������� ������� �������. ���� �� �����\0";
}

const char* bad_parallelogram_angle::what() const noexcept
{
	return "���������� ������� ��������������. ���� ������� �� �����\0";
}

const char* bad_parallelogram_side::what() const noexcept
{
	return "���������� ������� ��������������. ������� ������� �� �����\0";
}

const char* bad_rhombus_side::what() const noexcept
{
	return "���������� ������� ����. ������� �� �����\0";
}

const char* bad_rhombus_angle::what() const noexcept
{
	return "���������� ������� ����. ���� ������� �� �����\0";
}