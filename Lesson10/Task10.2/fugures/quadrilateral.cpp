#include<iostream>

#include "quadrilateral.h"

Quadrilateral::Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;

	name = "Четырехугольник";
	numberOfSides = 4;
	numberOfAngles = 4;
}

void Quadrilateral::print_info() {

	std::cout << name << ":\n";
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d="<< d << std::endl;
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}