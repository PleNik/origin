#include "square.h"

FiguresDynamic::Square::Square(double a) : Rectangle(a, a) {

	name = "�������";
}

FIGURESLIBRARY_API void FiguresDynamic::Square::print_info()
{
	Quadrilateral::print_info();
}