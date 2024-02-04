#pragma once

#include"rectangle.h"

namespace FiguresDynamic {
	class Square : public Rectangle {
	public:
		FIGURESLIBRARY_API Square(double a);

		FIGURESLIBRARY_API void print_info() override;
	};

}
