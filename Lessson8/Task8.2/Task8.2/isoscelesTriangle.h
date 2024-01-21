#pragma once

#include"triangle.h"

class IsoscelesTriangle: public Triangle  {

protected:
	void check() override;

public:
	IsoscelesTriangle(double a, double b, double A, double B);

	void print_info() override;
};

