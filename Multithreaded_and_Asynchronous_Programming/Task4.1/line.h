#pragma once

#include"shape.h"

class Line : public Shape {


public:
	Line();
	void setPoint1(int aX1, int aY1);
	void setPoint2(int aX2, int aY2);

	void print_info() override;
	
	void shift(int axialShiftCoefficient) override;
	void scaleX(int scalingFactor) override;
	void scaleY(int scalingFactor) override;
	void scale(int scalingFactor) override;

protected:
	PointXY mPoint1;
	PointXY mPoint2;
};