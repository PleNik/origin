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

	if (numberOfSides != 3)
		throw FigureException("���������� ������ �� ����� ����");

	if ((A + B + C) != 180)
		throw FigureException("����� ����� �� ����� 180");

}

void Triangle::print_info() {
	std::cout << name << " (������� " << a << ", " << b << ", " << c << "; ���� "
		<< A << ", " << B << ", " << C << ") ������" << std::endl;
	
}

