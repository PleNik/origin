#include <iostream>
#include"math.h"


int main()
{
	setlocale(LC_ALL, "ru");

	double a{}, b{};
	std::cout << "Введите первое число: ";
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	
	int userInput{};
	std::cout << "Введите операцию (1- сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень):";
	std::cin >> userInput;

	switch (userInput)
	{
	case 1:
		std::cout << a << "+" << b << "=" << addition(a, b) << std::endl;
		break;
	case 2:
		std::cout << a << "-" << b << "=" << subtraction(a, b) << std::endl;
		break;
	case 3:
		std::cout << a << "*" << b << "=" << multiplication(a, b) << std::endl;
		break;
	case 4:
		if (!b) {
			std::cout << "Неверный ввод, деление на ноль" << std::endl;
			exit;
		}
		std::cout << a << "/" << b << "=" << division(a, b) << std::endl;
		break;
	case 5:
		std::cout << a << " в степени " << b << " = " << exponentiation(a, b) << std::endl;
		break;
	}

	return 0;
}