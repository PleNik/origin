#include "RightTriangle.h"

RightTriangle::RightTriangle(double a, double b, double c, double A, double B) :Triangle(a, b, c, A, B, 90) {

	name = "Прямоугольный треугольник";
}


void RightTriangle::print_info() {

	Triangle::print_info();
}

void RightTriangle::check() {

	Triangle::check();
	if (C != 90)
		throw FigureException("Угол С не равен 90");

}
