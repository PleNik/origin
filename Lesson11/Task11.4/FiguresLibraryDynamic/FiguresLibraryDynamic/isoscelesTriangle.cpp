#include "isoscelesTriangle.h"

FiguresDynamic::IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B) :Triangle(a, b, a, A, B, A) {

	name = "Равнобедренный треугольник";
}

FIGURESLIBRARY_API void FiguresDynamic::IsoscelesTriangle::print_info() {

	Triangle::print_info();
}
