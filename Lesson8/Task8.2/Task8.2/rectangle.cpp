#include "rectangle.h"

Rectangle::Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {

	name = "�������������";

	if (a != c && b != d)
		throw FigureException("������� a, c  � b, d ������� �� �����");

	if (A != 90 && B != 90 && C != 90 && D != 90)
		throw FigureException("��� ���� �� ����� 90");
}

void Rectangle::print_info() {

	Quadrilateral::print_info();
}