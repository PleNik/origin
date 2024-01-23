#include<iostream>

#include "quadrilateral.h"


Quadrilateral::Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D){
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

	if (numberOfSides != 4)
		throw FigureException("количество сторон не равно 4");

	if ((A + B + C + D) != 360)
		throw FigureException("сумма углов не равна 360");
}

void Quadrilateral::print_info() {

	try {
		std::cout << name << " (стороны " << a << ", " << b << ", "<< c <<", "<< d << "; углы "
			<< A << ", " << B << ", " << C <<", " << D << ") создан" << std::endl;

	}
	catch (const FigureException& ex) {
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}
}
