#pragma once

#include"parallelogram.h"

class Rhombus : public  Parallelogram {

protected:
	void check() override;

public:
	Rhombus(double a, double A, double B);

	void print_info() override;
};

