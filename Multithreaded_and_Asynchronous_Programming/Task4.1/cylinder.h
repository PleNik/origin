#pragma once

#include"shape.h"

class Cylinder : public Shape {
public:
	Cylinder();

	void setPoint1(int aX1, int aY1, int aZ1);
	void setPoint2(int aX2, int aY2, int aZ2);
	void setPoint3(int aX3, int aY3, int aZ3);
	void setPoint4(int aX4, int aY4, int aZ4);
	void setPoint5(int aX5, int aY5, int aZ5);

	void print_info() override;

	void shift(int axialShiftCoefficient) override;
	void scaleX(int scalingFactor) override;
	void scaleY(int scalingFactor) override;
	void scale(int scalingFactor) override;

protected:
	PointXYZ mPoint1;
	PointXYZ mPoint2;
	PointXYZ mPoint3;
	PointXYZ mPoint4;
	PointXYZ mPoint5;
};
