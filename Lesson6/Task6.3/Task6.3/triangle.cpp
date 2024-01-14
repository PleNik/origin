#include"figure.h"
#include "triangle.h"


Triangle::Triangle(double a, double b, double c, double A, double B, double C) {
	this->a = a;
	this->b = b;
	this->c = c;

	this->A = A;
	this->B = B;
	this->C = C;

	name = "Треугольник";
}

double Triangle::getSide_a()
{
	return a;
}

double Triangle::getSide_b()
{
	return b;
}

double Triangle::getSide_c()
{
	return c;
}

double Triangle::getAngle_A()
{
	return A;
}

double Triangle::getAngle_B()
{
	return B;
}

double Triangle::getAngle_C()
{
	return C;
}

std::string Triangle::getName()
{
	return name;
}


