#include<iostream>

#include "triangle.h"
#include "rightTriangle.h"

FiguresDynamic::RightTriangle::RightTriangle(double a, double b, double c, double A, double B):Triangle(a, b, c, A, B, 90){

	name = "Прямоугольный треугольник";
}

FIGURESLIBRARY_API void FiguresDynamic::RightTriangle::print_info() {

	Triangle::print_info();
}
