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

	name = "�����������";
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
		std::cout << name << " (������� " << a << ", " << b << ", "<< c << "; ���� " <<A << ", " << B << ", " << C<< ") ������" << std::endl;

	}
	catch (const FigureException& ex) {
		std::cout << "������ �������� ������. �������: " << ex.what() << std::endl;
	}

}

void Triangle::check() {

	if (numberOfSides != 3)
		throw FigureException("���������� ������ �� ����� 3");

	if ((A + B + C) != 180)
		throw FigureException("����� ����� �� ����� 180");
}


