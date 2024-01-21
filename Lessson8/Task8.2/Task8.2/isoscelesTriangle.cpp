#include "isoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B) :Triangle(a, b, a, A, B, A) {
	name = "�������������� �����������";
}

void IsoscelesTriangle::print_info() {

	Triangle::print_info();
}

void IsoscelesTriangle::check() {

	Triangle::check();

	if (a != c)
		throw FigureException("������� � �� ����� ������� �");
	if (A != C)
		throw FigureException("���� � �� ����� ���� �");
}


