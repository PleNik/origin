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

void print_info(FiguresDynamic::Figure* figure) {

    figure->print_info();
    std::cout << std::endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    FiguresDynamic::Triangle triangle(10, 20, 30, 70, 30, 60);
    print_info(&triangle);

    FiguresDynamic::RightTriangle rTriangle(10, 20, 30, 50, 40);
    print_info(&rTriangle);

    FiguresDynamic::IsoscelesTriangle isTriangle(10, 20, 40, 80);
    print_info(&isTriangle);

    FiguresDynamic::EquilateralTriangle eqTriangle(30);
    print_info(&eqTriangle);

    FiguresDynamic::Quadrilateral quart(10, 20, 30, 40, 110, 80, 70, 110);
    print_info(&quart);

    FiguresDynamic::Rectangle rectangle(10, 20);
    print_info(&rectangle);

    FiguresDynamic::Square square(20);
    print_info(&square);

    FiguresDynamic::Parallelogram paralgrm(20, 30, 50, 140);
    print_info(&paralgrm);

    FiguresDynamic::Rhombus rhombus(30, 40, 140);
    print_info(&rhombus);

    system("pause");

    return 0;
}