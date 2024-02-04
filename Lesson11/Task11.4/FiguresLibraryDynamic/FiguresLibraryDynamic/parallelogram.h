#pragma once

#include"rectangle.h"

namespace FiguresDynamic {

	class Parallelogram : public  Quadrilateral {
	public:
		FIGURESLIBRARY_API Parallelogram(double a, double b, double A, double B);

		FIGURESLIBRARY_API void print_info() override;
	};

}
