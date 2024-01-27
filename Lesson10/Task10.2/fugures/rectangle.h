#pragma once

#include"quadrilateral.h"

class Rectangle : public  Quadrilateral {
public:
	Rectangle(double a, double b);

	void print_info() override;
};