#include "parallelogram.h"

FiguresDynamic::Parallelogram::Parallelogram(double a, double b, double A, double B) :Quadrilateral(a, b, a, b, A, B, A, B) {

	name = "ֿאנאככוכמדנאלל";
}

FIGURESLIBRARY_API void FiguresDynamic::Parallelogram::print_info() {

	Quadrilateral::print_info();
}
