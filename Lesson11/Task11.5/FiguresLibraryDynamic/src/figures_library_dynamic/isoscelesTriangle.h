#pragma once

#include"triangle.h"

namespace FiguresDynamic {
	class IsoscelesTriangle : public Triangle {

	public:
		FIGURESLIBRARY_API  IsoscelesTriangle(double a, double b, double A, double B);

		FIGURESLIBRARY_API  void print_info() override;
	};
}