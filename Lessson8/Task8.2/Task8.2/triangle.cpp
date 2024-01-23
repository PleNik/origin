#include<iostream>

//#include"figure.h"
#include "triangle.h"

Triangle::Triangle(double a, double b, double c, double A, double B, double C) {

	this->a = a;
	this->b = b;
	this->c = c;

	this->A = A;
	this->B = B;
	this->C = C;

	name = "Треугольник";
	numberOfSides = 3;
	numberOfAngles = 3;

	if (numberOfSides != 3)
		throw FigureException("количество сторон не равно трем");

	if ((A + B + C) != 180)
		throw FigureException("сумма углов не равна 180");

}

void Triangle::print_info() {
	std::cout << name << " (стороны " << a << ", " << b << ", " << c << "; углы "
		<< A << ", " << B << ", " << C << ") создан" << std::endl;
	
}

