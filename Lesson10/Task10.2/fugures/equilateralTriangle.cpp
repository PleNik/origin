#include "equilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
	name = "�������������� �����������";
}

void EquilateralTriangle::print_info() {

	Triangle::print_info();
}