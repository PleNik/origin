#pragma once

#include<string>

#include"FigureException.h"

class Figure {
protected:
	std::string name;
	int numberOfSides{};
	int numberOfAngles{};
	virtual void check();

public:
	Figure();

	virtual void print_info();
};