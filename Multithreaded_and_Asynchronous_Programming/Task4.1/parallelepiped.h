#pragma once

#include"cylinder.h"

class Parallelepiped : public Cylinder {

public:
	Parallelepiped();

	void setPoint6(int aX6, int aY6, int aZ6);
	void setPoint7(int aX7, int aY7, int aZ7);
	void setPoint8(int aX8, int aY8, int aZ8);

	void print_info() override;

	void shift(int axialShiftCoefficient) override;
	void scaleX(int scalingFactor) override;
	void scaleY(int scalingFactor) override;
	void scaleZ(int scalingFactor) override;
	void scale(int scalingFactor) override;

protected:
	PointXYZ mPoint6;
	PointXYZ mPoint7;
	PointXYZ mPoint8;
};
