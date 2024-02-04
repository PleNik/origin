#pragma once

#include"parallelogram.h"

namespace FiguresDynamic {

	class Rhombus : public  Parallelogram {
	public:
		FIGURESLIBRARY_API Rhombus(double a, double A, double B);

		FIGURESLIBRARY_API void print_info() override;
	};

}
