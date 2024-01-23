#include <iostream>

class DivisionByZeroExceptoin :public std::exception {
public:
	const char* what()const override {
		return "Попытка деления на 0";
	}
};

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;

		if (!denominator)
			throw DivisionByZeroExceptoin();
	}

	int division() {
		return numerator_ / denominator_;
	}

	bool operator == (Fraction otherFraction) {
		return division() == otherFraction.division();
	}

	bool operator != (Fraction otherFraction) {
		return !(*this==otherFraction);
	}

	bool operator < (Fraction otherFraction) {
		return division() < otherFraction.division();
	}

	bool operator > (Fraction otherFraction) {
		return  otherFraction < *this;
	}

	bool operator <= (Fraction otherFraction) {
		return !(*this > otherFraction);
	}

	bool operator >= (Fraction otherFraction) {
		return !(*this < otherFraction);
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	Fraction f1(4, 3);
	Fraction f2(6, 11);

	try	{
		std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
		std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
		std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
		std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
		std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
		std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	}
	catch (const DivisionByZeroExceptoin& ex)	{
		std::cout << ex.what() << std::endl;
	}
	
	return 0;
}