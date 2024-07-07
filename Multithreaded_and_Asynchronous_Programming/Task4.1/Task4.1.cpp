#include <iostream>

#include"line.h"
#include"rectangle.h"
#include"circle.h"
#include"parallelepiped.h"

void print_info(Shape* shape) {
	shape->print_info();
	std::cout << std::endl;
}

void shift(Shape* shape, int axialShiftCoefficient) {
	shape->shift(axialShiftCoefficient);
}

void scaleX(Shape* shape, int scalingFactor) {
	shape->scaleX(scalingFactor);
}

void scaleY(Shape* shape, int scalingFactor) {
	shape->scaleY(scalingFactor);
}

void scaleZ(Shape* shape, int scalingFactor) {
	shape->scaleZ(scalingFactor);
}


void scale(Shape* shape, int scalingFactor) {
	shape->scale(scalingFactor);
}

int main() {

	/*Line line;
	line.setPoint1(1, 1);
	line.setPoint2(2, 2);
	std::cout << "Line before conversion" << std::endl;
	print_info(&line);
	shift(&line, 2);
	std::cout << "Line after axial shift" << std::endl;
	print_info(&line);

	scaleX(&line, 6);
	std::cout << "Line after scaleing X" << std::endl;
	print_info(&line);
	scaleY(&line, 4);
	std::cout << "Line after scaleing Y" << std::endl;
	print_info(&line);

	scale(&line, 2);
	std::cout << "Line after scaleing" << std::endl;
	print_info(&line);*/

	/*Rectangle rectangle;
	rectangle.setPoint1(2, 3);
	rectangle.setPoint2(0, 1);
	rectangle.setPoint3(3, 4);
	rectangle.setPoint4(4, 5);
	std::cout << "Rectangle before conversion" << std::endl;
	print_info(&rectangle);

	shift(&rectangle, 2);
	std::cout << "Rectangle after axial shift" << std::endl;
	print_info(&rectangle);

	scaleX(&rectangle, 4);
	std::cout << "Rectangle after scaleing X" << std::endl;
	print_info(&rectangle);

	scaleY(&rectangle, 3);
	std::cout << "Rectangle after scaleing Y" << std::endl;
	print_info(&rectangle);

	scale(&rectangle, 4);
	std::cout << "Rectangle after scaleing" << std::endl;
	print_info(&rectangle);*/

	/*Circle circle;
	circle.setPoint1(3, 4);
	circle.setPoint2(5, 5);
	std::cout << "Circle before conversion" << std::endl;
	print_info(&circle);
	shift(&circle, 3);
	std::cout << "Circle after axial shift" << std::endl;
	print_info(&circle);

	scaleX(&circle, 4);
	std::cout << "Circle after scaleing X" << std::endl;
	print_info(&circle);
	scaleY(&circle, 5);
	std::cout << "Circle after scaleing Y" << std::endl;
	print_info(&circle);

	scale(&circle, 4);
	std::cout << "Circle after scaleing" << std::endl;
	print_info(&circle);*/

	/*Parallelepiped parallelepiped;
	parallelepiped.setPoint1(2, 3, 1);
	parallelepiped.setPoint2(0, 1, 4);
	parallelepiped.setPoint3(3, 4, 2);
	parallelepiped.setPoint4(4, 5, 1);
	parallelepiped.setPoint5(1, 3, 1);
	parallelepiped.setPoint6(5, 2, 3);
	parallelepiped.setPoint7(6, 0, 3);
	parallelepiped.setPoint8(1, 5, 5);

	std::cout << "Parallelepiped before conversion" << std::endl;
	print_info(&parallelepiped);

	shift(&parallelepiped, 2);
	std::cout << "Parallelepiped after axial shift" << std::endl;
	print_info(&parallelepiped);

	scaleX(&parallelepiped, 4);
	std::cout << "Parallelepiped after scaleing X" << std::endl;
	print_info(&parallelepiped);

	scaleY(&parallelepiped, 3);
	std::cout << "Parallelepiped after scaleing Y" << std::endl;
	print_info(&parallelepiped);

	scaleZ(&parallelepiped, 2);
	std::cout << "Parallelepiped after scaleing Z" << std::endl;
	print_info(&parallelepiped);

	scale(&parallelepiped, 4);
	std::cout << "Parallelepipede after scaleing" << std::endl;
	print_info(&parallelepiped);*/

	Cylinder cylinder;
	cylinder.setPoint1(2, 3, 1);
	cylinder.setPoint2(0, 1, 4);
	cylinder.setPoint3(3, 4, 2);
	cylinder.setPoint4(4, 5, 1);
	cylinder.setPoint5(1, 3, 1);

	std::cout << "Cylinder before conversion" << std::endl;
	print_info(&cylinder);

	shift(&cylinder, 2);
	std::cout << "Cylinder after axial shift" << std::endl;
	print_info(&cylinder);

	scaleX(&cylinder, 4);
	std::cout << "Cylinder after scaleing X" << std::endl;
	print_info(&cylinder);

	scaleY(&cylinder, 3);
	std::cout << "Cylinder after scaleing Y" << std::endl;
	print_info(&cylinder);

	scaleZ(&cylinder, 2);
	std::cout << "Cylinder after scaleing Z" << std::endl;
	print_info(&cylinder);

	scale(&cylinder, 4);
	std::cout << "Cylinder after scaleing" << std::endl;
	print_info(&cylinder);

	return 0;
}