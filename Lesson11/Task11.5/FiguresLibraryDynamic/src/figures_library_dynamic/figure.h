#pragma once

#include<string>

#ifndef FIGURESLIBRARYDYNAMIC_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif //FIGURESLIBRARYDYNAMIC_EXPORTS

namespace FiguresDynamic {

	class Figure {
	protected:
		std::string name;
		int numberOfSides{};
		int numberOfAngles{};

	public:
		FIGURESLIBRARY_API Figure();

		FIGURESLIBRARY_API virtual void print_info();

	};
}

