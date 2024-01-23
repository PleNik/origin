#pragma once

#include"triangle.h"

class IsoscelesTriangle: public Triangle  {

public:
	IsoscelesTriangle(double a, double b, double A, double B);

	void print_info() override;
};

