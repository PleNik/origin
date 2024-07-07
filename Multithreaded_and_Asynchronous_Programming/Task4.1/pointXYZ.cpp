#include "pointXYZ.h"

PointXYZ::PointXYZ (){}

void PointXYZ::setPoint(int aX, int aY, int aZ) {
	mX = aX;
	mY = aY;
	mZ = aZ;
}

int PointXYZ::getZ() const {
	return mZ;
}

void PointXYZ::shiftPoint(int axialShiftCoefficien) {
	mX += axialShiftCoefficien;
	mY += axialShiftCoefficien;
	mZ = +axialShiftCoefficien;
}

void PointXYZ::scalePointZ(int scalingFactor) {
	mZ *= scalingFactor;
}

void PointXYZ::scalePoint(int scalingFactor) {
	mX /= scalingFactor;
	mY /= scalingFactor;
	mZ /= scalingFactor;
}
