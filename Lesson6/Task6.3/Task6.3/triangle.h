#pragma once

#include"figure.h"

class Triangle:public Figure{
protected:
	double a{}, b{}, c{}; //стороны
	double A{}, B{}, C{}; //углы

public:
	Triangle(double a, double b, double c, double A, double B, double C);

	double getSide_a();
	double getSide_b();
	double getSide_c();
	double getAngle_A();
	double getAngle_B();
	double getAngle_C();
	std::string getName();
};

