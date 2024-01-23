#include "square.h"

Square::Square(double a) : Rectangle(a, a) {

	name = "�������";

	if (a != b && a != c && a != d && b != c && b != d && c != d)
		throw FigureException("��� ������� �� �����");

	if (A != 90 && B != 90 && C != 90 && D != 90)
		throw FigureException("��� ���� �� ����� 90");
}

void Square::print_info() {

	Quadrilateral::print_info();
}