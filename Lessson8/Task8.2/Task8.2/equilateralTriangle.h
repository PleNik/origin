#pragma once

#include"triangle.h"

class EquilateralTriangle: public Triangle{

protected:
	void check() override;

public:
	EquilateralTriangle(double a);

	void print_info() override;

};

