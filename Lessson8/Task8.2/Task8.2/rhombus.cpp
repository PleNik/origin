#include "rhombus.h"

Rhombus::Rhombus(double a, double A, double B) :Parallelogram(a, a, A, B) {
	name = "����";
}

void Rhombus::print_info() {

	Quadrilateral::print_info();
}

void Rhombus::check() {

	Quadrilateral::check();

	if (a != b && a != c && a != d && b != c && b != d && c != d)
		throw FigureException("��� ������� �� �����");

	if (A != C && B != D)
		throw FigureException("���� �, � � B, D ������� �� �����");
}
