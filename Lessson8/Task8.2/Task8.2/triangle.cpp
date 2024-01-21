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

}

/*double Triangle::getSide_a() {
	return a;
}

double Triangle::getSide_b() {
	return b;
}

double Triangle::getSide_c() {
	return c;
}

double Triangle::getAngle_A() {
	return A;
}

double Triangle::getAngle_B() {
	return B;
}

double Triangle::getAngle_C() {
	return C;
}

std::string Triangle::getName() {
	return name;
}*/

void Triangle::print_info() {
	try {
		check();
		std::cout << name << " (стороны " << a << ", " << b << ", "<< c << "; углы " <<A << ", " << B << ", " << C<< ") создан" << std::endl;

	}
	catch (const FigureException& ex) {
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

}

void Triangle::check() {

	if (numberOfSides != 3)
		throw FigureException("Количество сторон не равно 3");

	if ((A + B + C) != 180)
		throw FigureException("Сумма углов не равна 180");
}


