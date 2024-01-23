#pragma once

#include"triangle.h"

class EquilateralTriangle: public Triangle{
public:
	EquilateralTriangle(double a);

	void print_info() override;
};

