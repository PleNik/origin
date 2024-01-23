#include "RightTriangle.h"

RightTriangle::RightTriangle(double a, double b, double c, double A, double B) :Triangle(a, b, c, A, B, 90) {

	name = "Прямоугольный треугольник";

	if (C != 90)
		throw FigureException("угол С не равен 90");
}


void RightTriangle::print_info() {

	Triangle::print_info();
}
