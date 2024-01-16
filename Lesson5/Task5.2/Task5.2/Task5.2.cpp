#include <iostream>
#include<string>

class Figure {

protected:
	std::string name;

public:
	void virtual print_info() {}
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

	void print_info() override {
		std::cout << this->getName() << ":\n";
		std::cout << "Стороны: a=" << this->getSide_a() << " b=" << this->getSide_b() << " c=" << this->getSide_c() << std::endl;
		std::cout << "Углы: А=" << this->getAngle_A() << " B=" << this->getAngle_B() << " C=" << this->getAngle_C() << std::endl;
		std::cout << std::endl;
	}
};

//прямоугольный треугольник
class RightTriangle : public Triangle {
public:
	RightTriangle(double a, double b, double c, double A, double B) :Triangle(a, b, c, A, B, 90) {
		name = "Прямоугольный треугольник";
	}

	void print_info() override {
		Triangle::print_info();
	}
};

//равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(double a, double b, double A, double B) :Triangle(a, b, a, A, B, A) {
		name = "Равнобедренный треугольник";
	}

	void print_info() override {
		Triangle::print_info();
	}
};

//равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
		name = "Равносторонний треугольник";
	}

	void print_info() override {
		Triangle::print_info();
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

	void print_info() override {
		std::cout << this->getName() << ":\n";
		std::cout << "Стороны: a=" << this->getSide_a() << " b=" << this->getSide_b() << " c=" << this->getSide_c() << " d=" << this->getSide_d() << std::endl;
		std::cout << "Углы: А=" << this->getAngle_A() << " B=" << this->getAngle_B() << " C=" << this->getAngle_C() << " D=" << this->getAngle_D() << std::endl;
		std::cout << std::endl;
	}
};

//прямоугольник
class Rectangle : public  Quadrilateral {
public:
	Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {

		name = "Прямоугольник";
	}

	void print_info() override {
		Quadrilateral::print_info();
	}
};

//квадрат
class Square : public Rectangle {
public:
	Square(double a) : Rectangle(a, a) {
		name = "Квадрат";
	}

	void print_info() override {
		Quadrilateral::print_info();
	}
};

//параллелограмм
class Parallelogram : public  Quadrilateral {
public:
	Parallelogram(double a, double b, double A, double B) :Quadrilateral(a, b, a, b, A, B, A, B) {
		name = "Параллелограмм";
	}

	void print_info() override {
		Quadrilateral::print_info();
	}
};

//ромб
class Rhombus : public  Parallelogram {
public:
	Rhombus(double a, double A, double B) :Parallelogram(a, a, A, B) {
		name = "Ромб";
	}

	void print_info() override {
		Quadrilateral::print_info();
	}
};

void print_info(Figure* figure) {
	figure->print_info();
}

int main()
{
	setlocale(LC_ALL, "ru");

	Triangle triangle(10, 20, 30, 50, 60, 70);
	print_info(&triangle);

	RightTriangle rTriangle(10, 20, 30, 50, 60);
	print_info(&rTriangle);

	IsoscelesTriangle isTriangle(10, 20, 50, 60);
	print_info(&isTriangle);

	EquilateralTriangle eqTriangle(30);
	print_info(&eqTriangle);

	Quadrilateral quart(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&quart);

	Rectangle rectangle(10, 20);
	print_info(&rectangle);

	Square square(20);
	print_info(&square);

	Parallelogram paralgrm(20, 30, 30, 40);
	print_info(&paralgrm);

	Rhombus rhombus(30, 30, 40);
	print_info(&rhombus);

	
    return 0;
}