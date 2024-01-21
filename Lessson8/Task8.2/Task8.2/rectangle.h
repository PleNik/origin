#pragma once

#include"quadrilateral.h"

class Rectangle : public  Quadrilateral {

protected:
	void check() override;

public:
	Rectangle(double a, double b);

	void print_info() override;
};

