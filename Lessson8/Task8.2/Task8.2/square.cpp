#include "square.h"

Square::Square(double a) : Rectangle(a, a) {

	name = " вадрат";
}

void Square::print_info() {

	Quadrilateral::print_info();
}

void Square::check() {

	Quadrilateral::check();

	if (a != b && a != c && a != d && b != c && b != d && c != d)
		throw FigureException("все стороны не равны");

	if (A != 90 && B != 90 && C != 90 && D != 90)
		throw FigureException("все углы не равны 90");
}