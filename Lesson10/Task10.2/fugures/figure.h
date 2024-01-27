#pragma once

#include<string>

class Figure {
protected:
	std::string name;
	int numberOfSides{};
	int numberOfAngles{};

public:
	Figure();

	virtual void print_info();
};