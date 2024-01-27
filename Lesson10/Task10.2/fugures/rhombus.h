#pragma once

#include"parallelogram.h"

class Rhombus : public  Parallelogram {
public:
	Rhombus(double a, double A, double B);

	void print_info() override;
};
