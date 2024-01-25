#include <iostream>

#include"Fraction.h"

int main() {

	setlocale(LC_ALL, "ru");

	std::cout << "Введите числитель дроби 1: ";
	int numerator1;
	std::cin >> numerator1;

	std::cout << "Введите знаменатель дроби 1: ";
	int denominator1;
	std::cin >> denominator1;

	std::cout << "Введите числитель дроби 2: ";
	int numerator2;
	std::cin >> numerator2;

	std::cout << "Введите знаменатель дроби 2: ";
	int denominator2;
	std::cin >> denominator2;

	try {
		Fraction f1(numerator1, denominator1);
		Fraction f2(numerator2, denominator2);

		std::cout << f1.getNumerator() << "/" << f1.getDenomirator() << " + " << f2.getNumerator() << "/" << f2.getDenomirator() << " = "
			<< (f1 + f2).getNumerator() << "/" << (f1 + f2).getDenomirator() << std::endl;

		std::cout << f1.getNumerator() << "/" << f1.getDenomirator() << " - " << f2.getNumerator() << "/" << f2.getDenomirator() << " = "
			<< (f1 - f2).getNumerator() << "/" << (f1 - f2).getDenomirator() << std::endl;

		std::cout << f1.getNumerator() << "/" << f1.getDenomirator() << " * " << f2.getNumerator() << "/" << f2.getDenomirator() << " = "
			<< (f1 * f2).getNumerator() << "/" << (f1 * f2).getDenomirator() << std::endl;

		std::cout << f1.getNumerator() << "/" << f1.getDenomirator() << " / " << f2.getNumerator() << "/" << f2.getDenomirator() << " = "
			<< (f1 / f2).getNumerator() << "/" << (f1 / f2).getDenomirator() << std::endl;

		std::cout << "++" << f1.getNumerator() << "/" << f1.getDenomirator() << " * " << f2.getNumerator() << "/" << f2.getDenomirator() << " = ";
		Fraction prefIncrMult = ++f1 * f2;
		std::cout << prefIncrMult.getNumerator() << "/" << prefIncrMult.getDenomirator() << std::endl;
		std::cout << "Значение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenomirator() << std::endl;

		std::cout << f1.getNumerator() << "/" << f1.getDenomirator() << "--  * " << f2.getNumerator() << "/" << f2.getDenomirator() << " = ";
		Fraction postIncr = f1--;
		Fraction postIncrMult = postIncr * f2;
		std::cout << postIncrMult.getNumerator() << "/" << postIncrMult.getDenomirator() << std::endl;
		std::cout << "Значение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenomirator() << std::endl;

	}
	catch (const DivisionByZeroExceptoin& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}