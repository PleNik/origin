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

	name = "���������������";
	numberOfSides = 4;
	numberOfAngles = 4;

	if (numberOfSides != 4)
		throw FigureException("���������� ������ �� ����� 4");

	if ((A + B + C + D) != 360)
		throw FigureException("����� ����� �� ����� 360");
}

void Quadrilateral::print_info() {

	try {
		std::cout << name << " (������� " << a << ", " << b << ", "<< c <<", "<< d << "; ���� "
			<< A << ", " << B << ", " << C <<", " << D << ") ������" << std::endl;

	}
	catch (const FigureException& ex) {
		std::cout << "������ �������� ������. �������: " << ex.what() << std::endl;
	}
}
