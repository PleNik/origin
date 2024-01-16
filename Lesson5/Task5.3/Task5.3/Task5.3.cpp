#include <iostream>
#include<string>

class Figure {
protected:
	std::string name;
	int numberOfSides{};
	int numberOfAngles{};

public:
	Figure() {
		name = "Фигура";
	}

	virtual void print_info() {
		std::cout << this->name << ":" << std::endl;
		!check() ? std::cout << "Првильная" << std::endl : std::cout << "Неправильная" << std::endl;
		std::cout << "Количество сторон: " << this->numberOfSides << std::endl;
		std::cout << std::endl;
	}

	virtual bool check() {
		return numberOfSides;
	}
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
		numberOfSides = 3;
		numberOfAngles = 3;
	}

	void print_info() override{
		std::cout << this->name << ":" << std::endl;
		check() ? std::cout << "Правильная" << std::endl : std::cout << "Неправильная" << std::endl;
		std::cout << "Количество сторон: " << this->numberOfSides << std::endl;
		std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << std::endl;
		std::cout << "Углы: A=" << this->A << " B=" << this->B << " C=" << this->C << std::endl;
		std::cout << std::endl;
	}

	bool check() override {
		return numberOfSides == 3 && (A + B + C) == 180;
	}
};

//прямоугольный треугольник
class RightTriangle : public Triangle {
public:
	RightTriangle(double a, double b, double c, double A, double B) :Triangle(a, b, c, A, B, 90) {
		name = "Прямоугольный треугольник";
	}

	void print_info() override{
	Triangle::print_info();
	}

	bool check() override {
		return Triangle::check() && C == 90;
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

	bool check() override {
		return Triangle::check() && a == c && A == C;
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

	bool check() override {
		return Triangle::check();
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
		numberOfSides = 4;
		numberOfAngles = 4;
	}

	void print_info() override {
		std::cout << this->name << ":" << std::endl;
		check() ? std::cout << "Правильная" << std::endl : std::cout << "Неправильная" << std::endl;
		std::cout << "Количество сторон: " << this->numberOfSides << std::endl;
		std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << " d=" << this->d << std::endl;
		std::cout << "Углы: A=" << this->A << " B=" << this->B << " C=" << this->C << " D=" << this->D << std::endl;
		std::cout << std::endl;
	}

	bool check() override {
		return numberOfSides == 4 && (A + B + C + D) == 360;
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

	bool check() override {
		return Quadrilateral::check() && a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90;
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

	bool check() override {
		return Quadrilateral::check();
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

	bool check() override {
		return  Quadrilateral::check() && a == c && b == d && A == C && B == D;
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

	bool check() override {
		return  Quadrilateral::check() && a == b && a == c && a == d && b == c && b == d && d == c
			&& A == C && B == D;
	}
};

void print_info(Figure* figure) {
	figure->print_info();
}

int main()
{
	setlocale(LC_ALL, "ru");

	Figure figure;
	print_info(&figure);

	Triangle treangle(10, 20, 30, 50, 60, 70);
	print_info(&treangle);

	RightTriangle rightTriangle(20, 30, 40, 60, 70);
	print_info(&rightTriangle);

	IsoscelesTriangle islesTriangle(20, 40, 50, 80);
	print_info(&islesTriangle);

	EquilateralTriangle equilTriangle(50);
	print_info(&equilTriangle);

	Quadrilateral quart(20, 30, 40, 50, 60, 70, 40, 30);
	print_info(&quart);

	Rectangle rectangle(20, 30);
	print_info(&rectangle);

	Square square(20);
	print_info(&square);

	Parallelogram paralgrm(20, 30, 30, 40);
	print_info(&paralgrm);

	Rhombus rhombus(30, 120, 60);
	print_info(&rhombus);


	return 0;
}