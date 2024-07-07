#include"cylinder.h"

Cylinder::Cylinder() {
	mName = "Cylinder";
}

void Cylinder::setPoint1(int aX1, int aY1, int aZ1) {
	mPoint1.setPoint(aX1, aY1, aZ1);
}

void Cylinder::setPoint2(int aX2, int aY2, int aZ2) {
	mPoint1.setPoint(aX2, aY2, aZ2);
}

void Cylinder::setPoint3(int aX3, int aY3, int aZ3) {
	mPoint1.setPoint(aX3, aY3, aZ3);
}

void Cylinder::setPoint4(int aX4, int aY4, int aZ4) {
	mPoint1.setPoint(aX4, aY4, aZ4);
}

void Cylinder::setPoint5(int aX5, int aY5, int aZ5) {
	mPoint1.setPoint(aX5, aY5, aZ5);
}


void Cylinder::print_info() {
	std::cout << mName << ":\n";
	std::cout << "x1 = " << mPoint1.getX() << "; " << "y1 = " << mPoint1.getY() << "; " << "z1 = " << mPoint1.getZ() << std::endl;
	std::cout << "x2 = " << mPoint2.getX() << "; " << "y2 = " << mPoint2.getY() << "; " << "z2 = " << mPoint2.getZ() << std::endl;
	std::cout << "x3 = " << mPoint3.getX() << "; " << "y3 = " << mPoint3.getY() << "; " << "z3 = " << mPoint3.getZ() << std::endl;
	std::cout << "x4 = " << mPoint4.getX() << "; " << "y4 = " << mPoint4.getY() << "; " << "z4 = " << mPoint4.getZ() << std::endl;
	std::cout << "x5 = " << mPoint5.getX() << "; " << "y5 = " << mPoint5.getY() << "; " << "z5 = " << mPoint5.getZ() << std::endl;
}

void Cylinder::shift(int axialShiftCoefficient) {
	mPoint1.shiftPoint(axialShiftCoefficient);
	mPoint2.shiftPoint(axialShiftCoefficient);
	mPoint3.shiftPoint(axialShiftCoefficient);
	mPoint4.shiftPoint(axialShiftCoefficient);
	mPoint5.shiftPoint(axialShiftCoefficient);
}

void Cylinder::scaleX(int scalingFactor) {
	mPoint1.scalePointX(scalingFactor);
	mPoint2.scalePointX(scalingFactor);
	mPoint3.scalePointX(scalingFactor);
	mPoint4.scalePointX(scalingFactor);
	mPoint5.scalePointX(scalingFactor);
}

void Cylinder::scaleY(int scalingFactor) {
	mPoint1.scalePointY(scalingFactor);
	mPoint2.scalePointY(scalingFactor);
	mPoint3.scalePointY(scalingFactor);
	mPoint4.scalePointY(scalingFactor);
	mPoint5.scalePointY(scalingFactor);
}

void Cylinder::scale(int scalingFactor) {
	mPoint1.scalePoint(scalingFactor);
	mPoint2.scalePoint(scalingFactor);
	mPoint3.scalePoint(scalingFactor);
	mPoint4.scalePoint(scalingFactor);
	mPoint5.scalePoint(scalingFactor);
}
