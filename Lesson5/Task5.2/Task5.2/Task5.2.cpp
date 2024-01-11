#include <iostream>
#include<string>

class Figure {

protected:
	std::string name;
};

//треугольник
class Triangle :public Figure {
protected:
	double a{}, b{}, c{}; //стороны
	double A{}, B{}, C{}; //углы

public:
	Triangle(double a, double b, double c, double A, double B, double C) {

		this->a = a;
		this->b = b;
		this->c = c;

		this->A = A;
		this->B = B;
		this->C = C;

		name = "Треугольник";
	}

	double getSide_a() {
		return a;
	}

	double getSide_b() {
		return b;
	}

	double getSide_c() {
		return c;
	}

	double getAngle_A() {
		return A;
	}

	double getAngle_B() {
		return B;
	}

	double getAngle_C() {
		return C;
	}

	std::string getName() {
		return name;
	}
};

//прямоугольный треугольник
class RightTriangle : public Triangle {
public:
	RightTriangle(double a, double b, double c, double A, double B) :Triangle(a, b, c, A, B, 90) {
		name = "Прямоугольный треугольник";
	}
};

//равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(double a, double b, double A, double B) :Triangle(a, b, a, A, B, A) {
		name = "Равнобедренный треугольник";
	}
};

//равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
		name = "Равносторонний треугольник";
	}
};

//четырехугольник
class Quadrilateral : public Figure {

protected:
	double a{}, b{}, c{}, d{}; //стороны
	double A{}, B{}, C{}, D{}; //углы


public:
	Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) {

		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;

		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;

		name = "Четырехугольник";
	}

	double getSide_a() {
		return a;
	}

	double getSide_b() {
		return b;
	}

	double getSide_c() {
		return c;
	}

	double getSide_d() {
		return d;
	}

	double getAngle_A() {
		return A;
	}

	double getAngle_B() {
		return B;
	}

	double getAngle_C() {
		return C;
	}

	double getAngle_D() {
		return D;
	}

	std::string getName() {
		return name;
	}
};

//прямоугольник
class Rectangle : public  Quadrilateral {
public:
	Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {

		name = "Прямоугольник";
	}
};

//квадрат
class Square : public Rectangle {
public:
	Square(double a) : Rectangle(a, a) {
		name = "Квадрат";
	}
};

//параллелограмм
class Parallelogram : public  Quadrilateral {
public:
	Parallelogram(double a, double b, double A, double B) :Quadrilateral(a, b, a, b, A, B, A, B) {
		name = "Параллелограмм";
	}
};

//ромб
class Rhombus : public  Parallelogram {
public:
	Rhombus(double a, double A, double B) :Parallelogram(a, a, A, B) {
		name = "Ромб";
	}
};

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
	std::cout << "Стороны: a=" << figure->getSide_a() << " b=" << figure->getSide_b() << " c=" << figure->getSide_c() << " d="<<figure->getSide_d()<<std::endl;
	std::cout << "Углы: А=" << figure->getAngle_A() << " B=" << figure->getAngle_B() << " C=" << figure->getAngle_C() <<" D="<<figure->getAngle_D()<< std::endl;
	std::cout << std::endl;
}
