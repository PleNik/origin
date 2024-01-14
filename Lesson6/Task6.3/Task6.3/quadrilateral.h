#pragma once

#include"figure.h"

class Quadrilateral: public Figure{
protected:
	double a{}, b{}, c{}, d{}; //стороны
	double A{}, B{}, C{}, D{}; //углы

public:
	Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D);

	double getSide_a();
	double getSide_b();
	double getSide_c();
	double getSide_d();
	double getAngle_A();
	double getAngle_B();
	double getAngle_C();
	double getAngle_D();
	std::string getName();

};

