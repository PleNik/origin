#include "line.h"

Line::Line() {
	mName = "Line";
}

void Line::setPoint1(int aX1, int aY1) {
	mPoint1.setPoint(aX1, aY1);
}

void Line::setPoint2(int aX2, int aY2) {
	mPoint2.setPoint(aX2, aY2);
}

void Line::print_info() {
	std::cout << mName << ":\n";
	std::cout << "x1 = " << mPoint1.getX() << "; " << "y1 = " <<mPoint1.getY() << "; " << "x2 = " << mPoint2.getX() << "; " << "y2 = " << mPoint2.getY() << std::endl;
}

void Line::shift(int axialShiftCoefficient) {
	mPoint1.shiftPoint(axialShiftCoefficient);
	mPoint2.shiftPoint(axialShiftCoefficient);
}

void Line::scaleX(int scalingFactor) {
	mPoint1.scalePointX(scalingFactor);
	mPoint2.scalePointX(scalingFactor);
}

void Line::scaleY(int scalingFactor) {
	mPoint1.scalePointY(scalingFactor);
	mPoint2.scalePointY(scalingFactor);
}

void Line::scale(int scalingFactor) {
	mPoint1.scalePoint(scalingFactor);
	mPoint2.scalePoint(scalingFactor);
}
