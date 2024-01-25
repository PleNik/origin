#include "Fraction.h"

void Fraction::abbreviatedFraction(int a, int b, int& numerator, int& denominator) {
	int maxValue{};

	abs(a) > abs(b) ? maxValue = abs(a) : maxValue = abs(b);

	int greatest_common_divisor{}; //наибольший общий делитель

	for (int i = 1; i <= maxValue; i++)
	{
		if (a % i == 0 && b % i == 0 && greatest_common_divisor < i)
		{
			greatest_common_divisor = i;
		}
	}

	numerator = a / greatest_common_divisor;
	denominator = b / greatest_common_divisor;
}

Fraction::Fraction(int numerator, int denominator) {

	numerator_ = numerator;
	denominator_ = denominator;

	if (!denominator_)
		throw DivisionByZeroExceptoin();
}

Fraction Fraction::operator+(Fraction otherFraction) {

	int num = numerator_ * otherFraction.denominator_ + otherFraction.numerator_ * denominator_;
	int denom = denominator_ * otherFraction.denominator_;

	int numerator{};
	int denominator{};

	abbreviatedFraction(num, denom, numerator, denominator);

	return Fraction(numerator, denominator);
}

Fraction Fraction::operator-(Fraction otherFraction) {

	int num = numerator_ * otherFraction.denominator_ - otherFraction.numerator_ * denominator_;
	int denom = denominator_ * otherFraction.denominator_;

	int numerator{};
	int denominator{};

	abbreviatedFraction(num, denom, numerator, denominator);

	return Fraction(numerator, denominator);
}

Fraction Fraction::operator*(Fraction otherFraction) {

	int num = numerator_ * otherFraction.numerator_;
	int denom = denominator_ * otherFraction.denominator_;

	int numerator{};
	int denominator{};

	abbreviatedFraction(num, denom, numerator, denominator);

	return Fraction(numerator, denominator);
}

Fraction Fraction::operator/(Fraction otherFraction) {

	int num = numerator_ * otherFraction.denominator_;
	int denom = denominator_ * otherFraction.numerator_;

	int numerator{};
	int denominator{};

	abbreviatedFraction(num, denom, numerator, denominator);

	return Fraction(numerator, denominator);
}

Fraction& Fraction::operator++() {

	this->numerator_ = this->numerator_ + this->denominator_;

	return *this;
}

Fraction& Fraction::operator--() {

	this->numerator_ = this->numerator_ - this->denominator_;

	return *this;
}

Fraction& Fraction::operator--(int value) {

	Fraction temp(*this);

	this->numerator_ = this->numerator_ - this->denominator_;

	return temp;
}

int Fraction::getNumerator() {

	return numerator_;
}

int Fraction::getDenomirator() {

	return denominator_;
}
