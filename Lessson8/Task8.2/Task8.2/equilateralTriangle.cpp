#include "equilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
	name = "Равносторонний треугольник";
}

void EquilateralTriangle::print_info() {
	
	Triangle::print_info();
}

void EquilateralTriangle::check() {

	Triangle::check();

	if (a != b && a != c && b != c)
		throw FigureException("стороны не равны");

	if(A!=60 && B!=60 && C!=60)
		throw FigureException("все углы не равны 60");
}
