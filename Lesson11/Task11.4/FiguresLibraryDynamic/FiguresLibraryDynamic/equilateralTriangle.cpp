#include "equilateralTriangle.h"

FiguresDynamic::EquilateralTriangle::EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {

	name = "�������������� �����������";
}

FIGURESLIBRARY_API void FiguresDynamic::EquilateralTriangle::print_info() {

	Triangle::print_info();
}
