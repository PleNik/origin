#pragma once

#include"line.h"

class Rectangle : public Line {
protected:
	PointXY mPoint3;
	PointXY mPoint4;

public:
	Rectangle();

	void setPoint3(int aX3, int aY3);
	void setPoint4(int aX4, int aY4);
	const int getX3() const;
	const int getY3() const;
	const int getX4() const;
	const int getY4() const;

	void print_info() override;

	void shift(int axialShiftCoefficient) override;

	void scaleX(int scalingFactor) override;
	void scaleY(int scalingFactor) override;

	void scale(int scalingFactor) override;
};
