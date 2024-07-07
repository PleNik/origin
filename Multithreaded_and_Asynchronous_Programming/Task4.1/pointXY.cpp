#include "pointXY.h"

PointXY::PointXY(){}

void PointXY::setPoint(int aX, int aY) {
	mX = aX;
	mY = aY;
}

int PointXY::getX() const {
	return mX;
}

int PointXY::getY() const {
	return mY;
}

void PointXY::shiftPoint(int axialShiftCoefficien) {
	mX += axialShiftCoefficien;
	mY += axialShiftCoefficien;
}

void PointXY::scalePointX(int scalingFactor) {
	mX *= scalingFactor;
}

void PointXY::scalePointY(int scalingFactor) {
	mY *= scalingFactor;
}

void PointXY::scalePoint(int scalingFactor) {
	mX /= scalingFactor;
	mY /= scalingFactor;
}
