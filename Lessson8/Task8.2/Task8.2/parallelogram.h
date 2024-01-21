#pragma once

#include"quadrilateral.h"

class Parallelogram : public  Quadrilateral {

protected:
	void check() override;

public:
	Parallelogram(double a, double b, double A, double B);

	void print_info() override;
};

