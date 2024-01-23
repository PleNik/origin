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


	try	{
		Triangle triangle(10, 20, 30, 70, 30, 60);
		print_info(&triangle);
	}
	catch (const FigureException& ex)	{
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	try	{
		RightTriangle rTriangle(10, 20, 30, 50, 40);
		print_info(&rTriangle);
	}
	catch (const FigureException& ex)	{
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	try	{
		IsoscelesTriangle isTriangle(10, 20, 40, 80);
		print_info(&isTriangle);
	}
	catch (const FigureException& ex)	{
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	try	{
		EquilateralTriangle eqTriangle(30);
		print_info(&eqTriangle);
	}
	catch (const FigureException& ex)	{
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	try	{
		Quadrilateral quart(10, 20, 30, 40, 110, 80, 70, 110);
		print_info(&quart);
	}
	catch (const FigureException& ex)	{
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	try	{
		Rectangle rectangle(10, 20);
		print_info(&rectangle);
	}
	catch (const FigureException& ex)	{
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	try	{
		Square square(20);
		print_info(&square);
	}
	catch (const FigureException& ex)	{
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	try	{
		Parallelogram paralgrm(20, 30, 50, 140);
		print_info(&paralgrm);
	}
	catch (const FigureException& ex) {
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	try	{
		Rhombus rhombus(30, 40, 140);
		print_info(&rhombus);
	}
	catch (const FigureException& ex) {
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	}

	
	
	return 0;
}