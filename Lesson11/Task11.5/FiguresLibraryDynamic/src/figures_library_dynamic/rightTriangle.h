#pragma once

#include"triangle.h"

namespace FiguresDynamic {

	class RightTriangle : public Triangle {

	public:
		FIGURESLIBRARY_API RightTriangle(double, double, double, double, double);

		FIGURESLIBRARY_API void print_info() override;
	};
}
