#include "rhombus.h"

FiguresDynamic::Rhombus::Rhombus(double a, double A, double B) : Parallelogram(a, a, A, B) {

	name = "Ромб";
}

FIGURESLIBRARY_API void FiguresDynamic::Rhombus::print_info()
{
	Quadrilateral::print_info();
}
