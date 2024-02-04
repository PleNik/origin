#pragma once

#include"triangle.h"

namespace FiguresDynamic {
	class EquilateralTriangle : public Triangle {
	public:
		FIGURESLIBRARY_API EquilateralTriangle(double a);

		FIGURESLIBRARY_API void print_info() override;
	};

}
