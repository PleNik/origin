#pragma once

#include"quadrilateral.h"

namespace FiguresDynamic {
	class Rectangle : public  Quadrilateral {
	public:
		FIGURESLIBRARY_API Rectangle(double a, double b);

		FIGURESLIBRARY_API void print_info() override;
	};
}
