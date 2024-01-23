#include "rhombus.h"

Rhombus::Rhombus(double a, double A, double B) :Parallelogram(a, a, A, B) {
	name = "����";

	if (a != b && a != c && a != d && b != c && b != d && c != d)
		throw FigureException("��� ������� �� �����");

	if (A != C && B != D)
		throw FigureException("���� �, � � B, D ������� �� �����");
}

void Rhombus::print_info() {

	Quadrilateral::print_info();
}