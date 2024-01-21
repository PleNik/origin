#include "equilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
	name = "�������������� �����������";
}

void EquilateralTriangle::print_info() {
	
	Triangle::print_info();
}

void EquilateralTriangle::check() {

	Triangle::check();

	if (a != b && a != c && b != c)
		throw FigureException("������� �� �����");

	if(A!=60 && B!=60 && C!=60)
		throw FigureException("��� ���� �� ����� 60");
}
