#include "rectangle.h"

Rectangle::Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {

	name = "Прямоугольник";
}

void Rectangle::print_info() {

	Quadrilateral::print_info();
}

void Rectangle::check() {

	Quadrilateral::check();

	if (a != c && b != d)
		throw FigureException("стороны a, c  и b, d попарно не равны");

	if (A != 90 && B != 90 && C != 90 && D != 90)
		throw FigureException("все углы не равны 90");
}

