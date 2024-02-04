#pragma once

#include"figure.h"

namespace FiguresDynamic {
	class Quadrilateral : public Figure {
	protected:
		double a{}, b{}, c{}, d{}; //�������
		double A{}, B{}, C{}, D{}; //����

	public:
		FIGURESLIBRARY_API Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D);

		FIGURESLIBRARY_API void print_info() override;
	};

}
