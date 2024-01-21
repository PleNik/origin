#pragma once

#include"triangle.h"

class RightTriangle : public Triangle {

protected:
	void check() override;

public:
	RightTriangle(double, double, double, double, double);

	void print_info() override;
};