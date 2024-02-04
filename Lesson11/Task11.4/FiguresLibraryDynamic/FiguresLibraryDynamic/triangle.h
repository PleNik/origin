#pragma once

#include"figure.h"

namespace FiguresDynamic {

	class Triangle :public Figure {
	protected:
		double a{}, b{}, c{}; //стороны
		double A{}, B{}, C{}; //углы

	public:
		FIGURESLIBRARY_API Triangle(double a, double b, double c, double A, double B, double C);

		FIGURESLIBRARY_API void print_info() override;
	};

}

