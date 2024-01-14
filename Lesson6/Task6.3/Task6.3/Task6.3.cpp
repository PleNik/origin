#include <iostream>

//#include"class_Figure.h"
#include"triangle.h"
#include"rightTriangle.h"
#include"isoscelesTriangle.h"
#include"equilateralTriangle.h"
#include"quadrilateral.h"
#include"rectangle.h"
#include"square.h"
#include"parallelogram.h"
#include"rhombus.h"

void print_infoTriangle(Triangle* figure);


void print_infoQuadr(Quadrilateral* figure);


int main()
{
	setlocale(LC_ALL, "ru");

	Triangle triangle(10, 20, 30, 50, 60, 70);
	print_infoTriangle(&triangle);

	RightTriangle rTriangle(10, 20, 30, 50, 60);
	print_infoTriangle(&rTriangle);

	IsoscelesTriangle isTriangle(10, 20, 50, 60);
	print_infoTriangle(&isTriangle);

	EquilateralTriangle eqTriangle(30);
	print_infoTriangle(&eqTriangle);

	Quadrilateral quart(10, 20, 30, 40, 50, 60, 70, 80);
	print_infoQuadr(&quart);

	Rectangle rectangle(10, 20);
	print_infoQuadr(&rectangle);

	Square square(20);
	print_infoQuadr(&square);

	Parallelogram paralgrm(20, 30, 30, 40);
	print_infoQuadr(&paralgrm);

	Rhombus rhombus(30, 30, 40);
	print_infoQuadr(&rhombus);


	return 0;
}

void print_infoTriangle(Triangle* figure)
{
	std::cout << figure->getName() << ":\n";
	std::cout << "Стороны: a=" << figure->getSide_a() << " b=" << figure->getSide_b() << " c=" << figure->getSide_c() << std::endl;
	std::cout << "Углы: А=" << figure->getAngle_A() << " B=" << figure->getAngle_B() << " C=" << figure->getAngle_C() << std::endl;
	std::cout << std::endl;
}

void print_infoQuadr(Quadrilateral* figure)
{
	std::cout << figure->getName() << ":\n";
	std::cout << "Стороны: a=" << figure->getSide_a() << " b=" << figure->getSide_b() << " c=" << figure->getSide_c() << " d=" << figure->getSide_d() << std::endl;
	std::cout << "Углы: А=" << figure->getAngle_A() << " B=" << figure->getAngle_B() << " C=" << figure->getAngle_C() << " D=" << figure->getAngle_D() << std::endl;
	std::cout << std::endl;
}
