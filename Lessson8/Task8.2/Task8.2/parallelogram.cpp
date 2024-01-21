#include "parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double A, double B) :Quadrilateral(a, b, a, b, A, B, A, B) {
	name = "��������������";
}

void Parallelogram::print_info() {

	Quadrilateral::print_info();
}

void Parallelogram::check() {

	Quadrilateral::check();

	if (a != c && b != d)
		throw FigureException("������� �, � � b, d ������� �� �����");

	if (A != C && B != D)
		throw FigureException("���� �, � � B, D ������� �� �����");
}
