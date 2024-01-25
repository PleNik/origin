#pragma once

#include<iostream>

#include"DivisionByZeroExceptoin.h"

class Fraction {
	int numerator_;
	int denominator_;

	//сокращение дроби
	void abbreviatedFraction(int a, int b, int& numerator, int& denominator);

public:
	Fraction(int numerator, int denominator);

	Fraction operator + (Fraction otherFraction);
	Fraction operator - (Fraction otherFraction);
	Fraction operator * (Fraction otherFraction);
	Fraction operator / (Fraction otherFraction);
	Fraction& operator ++ ();
	Fraction& operator -- ();
	Fraction& operator -- (int value);

	int getNumerator();
	int getDenomirator();
};

