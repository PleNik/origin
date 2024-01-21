#include <iostream>

#include"triangle.h"
#include"rightTriangle.h"
#include"isoscelesTriangle.h"
#include"equilateralTriangle.h"
#include"quadrilateral.h"
#include"rectangle.h"
#include"square.h"
#include"parallelogram.h"
#include"rhombus.h"
#include"FigureException.h"

void print_info(Figure* figure) {
	figure->print_info();
}
int main()
{
	setlocale(LC_ALL, "ru");

	Triangle triangle(10, 20, 30, 50, 70, 70);
	print_info(&triangle);

	RightTriangle rTriangle(10, 20, 30, 50, 40);
	print_info(&rTriangle);

	IsoscelesTriangle isTriangle(10, 20, 40, 80);
	print_info(&isTriangle);

	EquilateralTriangle eqTriangle(30);
	print_info(&eqTriangle);

	Quadrilateral quart(10, 20, 30, 40, 110, 80, 70, 110);
	print_info(&quart);

	Rectangle rectangle(10, 20);
	print_info(&rectangle);

	Square square(20);
	print_info(&square);

	Parallelogram paralgrm(20, 30, 50, 140);
	print_info(&paralgrm);

	Rhombus rhombus(30, 40, 140);
	print_info(&rhombus);
	
	return 0;
}