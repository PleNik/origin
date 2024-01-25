#pragma once

#include<iostream>

class DivisionByZeroExceptoin :public std::exception {
public:
	const char* what()const override;
};

