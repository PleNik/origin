#pragma once

#include"triangle.h"

class RightTriangle : public Triangle {

public:
	RightTriangle(double, double, double, double, double);

	void print_info() override;
};