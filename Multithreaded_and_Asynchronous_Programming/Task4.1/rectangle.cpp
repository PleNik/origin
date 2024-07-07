#include "rectangle.h"

Rectangle::Rectangle() {
	mName = "Rectangle";
}

void Rectangle::setPoint3(int aX3, int aY3) {
	mPoint3.setPoint(aX3, aY3);
}

void Rectangle::setPoint4(int aX4, int aY4) {
	mPoint4.setPoint(aX4, aY4);
}

const int Rectangle::getX3() const {return mPoint3.getX();}

const int Rectangle::getY3() const {return mPoint3.getY();}

const int Rectangle::getX4() const { return mPoint4.getX();}

const int Rectangle::getY4() const { return mPoint4.getY(); }

void Rectangle::print_info() {
	std::cout << mName << ":\n";
	std::cout << "x1 = " << mPoint1.getX() << "; " << "y1 = " << mPoint1.getY() << "; " << "x2 = " << mPoint2.getX() << "; " << "y2 = " << mPoint2.getY() << std::endl;
	std::cout << "x3 = " << mPoint3.getX() << "; " << "y3 = " << mPoint3.getY() << "; " << "x4 = " << mPoint4.getX() << "; " << "y4 = " << mPoint4.getY() << std::endl;
}

void Rectangle::shift(int axialShiftCoefficient) {
	mPoint1.shiftPoint(axialShiftCoefficient);
	mPoint2.shiftPoint(axialShiftCoefficient);
	mPoint3.shiftPoint(axialShiftCoefficient);
	mPoint4.shiftPoint(axialShiftCoefficient);
}

void Rectangle::scaleX(int scalingFactor) {
	mPoint1.scalePointX(scalingFactor);
	mPoint2.scalePointX(scalingFactor);
	mPoint3.scalePointX(scalingFactor);
	mPoint4.scalePointX(scalingFactor);
}

void Rectangle::scaleY(int scalingFactor) {
	mPoint1.scalePointY(scalingFactor);
	mPoint2.scalePointY(scalingFactor);
	mPoint3.scalePointY(scalingFactor);
	mPoint4.scalePointY(scalingFactor);
}

void Rectangle::scale(int scalingFactor) {
	mPoint1.scalePoint(scalingFactor);
	mPoint2.scalePoint(scalingFactor);
	mPoint3.scalePoint(scalingFactor);
	mPoint4.scalePoint(scalingFactor);
}


