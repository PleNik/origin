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
}

double Quadrilateral::getSide_a(){

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

std::string Quadrilateral::getName()
{
	return name;
}
