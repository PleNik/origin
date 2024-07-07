#pragma once

#include"pointXY.h"

class PointXYZ : public PointXY {
public:
	PointXYZ();

	void setPoint(int aX, int aY, int aZ);
	int getZ() const;

	void shiftPoint(int axialShiftCoefficien);
	void scalePointZ(int scalingFactor);
	void scalePoint(int scalingFactor);

protected:
	int mZ{};
};

