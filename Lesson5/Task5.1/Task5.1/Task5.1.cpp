#include <iostream>
#include<string>

class Figure
{
protected:
	int numberOfSides;
	std::string name;

public:
	Figure()
	{
		numberOfSides = 0;
		name = "Фигура";
	}

	int getNumberOfSides()
	{
		return numberOfSides;
	}

	std::string getName()
	{
		return name;
	}
};

class Triangle:public Figure
{
public:
	Triangle()
	{
		numberOfSides = 3;
		name = "Треугольник";
	}
};

class Quadrangle:public Figure
{
public:
	Quadrangle()
	{
		numberOfSides = 4;
		name = "Четырехугольник";
	}
};


int main()
{
	setlocale(LC_ALL, "ru");

	Figure f;
	Triangle t;
	Quadrangle q;

	std::cout << "Количество сторон:" << std::endl;
	std::cout << f.getName() << ": " << f.getNumberOfSides() << std::endl;
	std::cout << t.getName() << ": " << t.getNumberOfSides() << std::endl;
	std::cout << q.getName() << ": " << q.getNumberOfSides() << std::endl;


	return 0;
}