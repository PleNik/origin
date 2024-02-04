#include "rectangle.h"

FiguresDynamic::Rectangle::Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {

	name = "Прямоугольник";
}

FIGURESLIBRARY_API void FiguresDynamic::Rectangle::print_info() {
	Quadrilateral::print_info();
}
