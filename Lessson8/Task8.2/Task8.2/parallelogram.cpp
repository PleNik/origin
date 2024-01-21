#include "parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double A, double B) :Quadrilateral(a, b, a, b, A, B, A, B) {
	name = "Параллелограмм";
}

void Parallelogram::print_info() {

	Quadrilateral::print_info();
}

void Parallelogram::check() {

	Quadrilateral::check();

	if (a != c && b != d)
		throw FigureException("стороны а, с и b, d попарно не равны");

	if (A != C && B != D)
		throw FigureException("углы А, С и B, D попарно не равны");
}
