#include "parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double A, double B) :Quadrilateral(a, b, a, b, A, B, A, B) {
	name = "ֿאנאככוכמדנאלל";
}

void Parallelogram::print_info() {

	Quadrilateral::print_info();
}