#pragma once

#include<iostream>

class FigureException: public std::domain_error
{
public:
	FigureException(const char* message);
	
};