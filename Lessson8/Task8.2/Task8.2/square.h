#pragma once

#include"rectangle.h"

class Square : public Rectangle {

protected:
	void check() override;

public:
	Square(double a);

	void print_info() override;
};

