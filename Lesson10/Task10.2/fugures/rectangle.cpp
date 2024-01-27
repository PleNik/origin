#include "rectangle.h"

Rectangle::Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {

	name = "Прямоугольник";
}

void Rectangle::print_info() {

	Quadrilateral::print_info();
}