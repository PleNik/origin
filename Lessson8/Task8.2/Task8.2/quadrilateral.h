#pragma once

#include"figure.h"

class Quadrilateral: public Figure{
protected:
	double a{}, b{}, c{}, d{}; //�������
	double A{}, B{}, C{}, D{}; //����

public:
	Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D);

	void print_info() override;
};

