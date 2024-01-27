#include "square.h"

Square::Square(double a) : Rectangle(a, a) {

	name = " вадрат";
}

void Square::print_info() {

	Quadrilateral::print_info();
}