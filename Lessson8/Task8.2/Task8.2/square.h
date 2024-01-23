#pragma once

#include"rectangle.h"

class Square : public Rectangle {
public:
	Square(double a);

	void print_info() override;
};

