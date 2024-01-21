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
}

/*double Quadrilateral::getSide_a() {

	return a;
}

double Quadrilateral::getSide_b(){

	return b;
}

double Quadrilateral::getSide_c() {
	return c;
}

double Quadrilateral::getSide_d() {

	return d;
}

double Quadrilateral::getAngle_A() {

	return A;
}

double Quadrilateral::getAngle_B() {

	return B;
}

double Quadrilateral::getAngle_C() {

	return C;
}

double Quadrilateral::getAngle_D() {

	return D;
}

std::string Quadrilateral::getName() {
	return name;
}*/

void Quadrilateral::print_info() {

	try {
		check();
		std::cout << name << " (������� " << a << ", " << b << ", "<< c <<", "<< d << "; ���� "
			<< A << ", " << B << ", " << C <<", " << D << ") ������" << std::endl;

	}
	catch (const FigureException& ex) {
		std::cout << "������ �������� ������. �������: " << ex.what() << std::endl;
	}
}

void Quadrilateral::check() {

	if(numberOfSides != 4)
		throw FigureException("���������� ������ �� ����� 4");

	if ((A + B + C + D) != 360)
		throw FigureException("����� ����� �� ����� 360");
}

