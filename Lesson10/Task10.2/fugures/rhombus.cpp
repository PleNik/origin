#include "rhombus.h"

Rhombus::Rhombus(double a, double A, double B) :Parallelogram(a, a, A, B) {
	name = "����";
}

void Rhombus::print_info() {

	Quadrilateral::print_info();
}