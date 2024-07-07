#include "parallelepiped.h"

Parallelepiped::Parallelepiped() {
	mName = "Parallelepiped";
}


void Parallelepiped::setPoint6(int aX6, int aY6, int aZ6) {
	mPoint1.setPoint(aX6, aY6, aZ6);
}

void Parallelepiped::setPoint7(int aX7, int aY7, int aZ7) {
	mPoint1.setPoint(aX7, aY7, aZ7);
}

void Parallelepiped::setPoint8(int aX8, int aY8, int aZ8) {
	mPoint1.setPoint(aX8, aY8, aZ8);
}

void Parallelepiped::print_info() {
	std::cout << mName << ":\n";
	std::cout << "x1 = " << mPoint1.getX() << "; " << "y1 = " << mPoint1.getY() << "; " << "z1 = " << mPoint1.getZ() << std::endl;
	std::cout << "x2 = " << mPoint2.getX() << "; " << "y2 = " << mPoint2.getY() << "; " << "z2 = " << mPoint2.getZ() << std::endl;
	std::cout << "x3 = " << mPoint3.getX() << "; " << "y3 = " << mPoint3.getY() << "; " << "z3 = " << mPoint3.getZ() << std::endl;
	std::cout << "x4 = " << mPoint4.getX() << "; " << "y4 = " << mPoint4.getY() << "; " << "z4 = " << mPoint4.getZ() << std::endl;
	std::cout << "x5 = " << mPoint5.getX() << "; " << "y5 = " << mPoint5.getY() << "; " << "z5 = " << mPoint5.getZ() << std::endl;
	std::cout << "x6 = " << mPoint6.getX() << "; " << "y6 = " << mPoint6.getY() << "; " << "z6 = " << mPoint6.getZ() << std::endl;
	std::cout << "x7 = " << mPoint7.getX() << "; " << "y7 = " << mPoint7.getY() << "; " << "z7 = " << mPoint7.getZ() << std::endl;
	std::cout << "x8 = " << mPoint8.getX() << "; " << "y8 = " << mPoint8.getY() << "; " << "z8 = " << mPoint8.getZ() << std::endl;
}

void Parallelepiped::shift(int axialShiftCoefficient) {
	mPoint1.shiftPoint(axialShiftCoefficient);
	mPoint2.shiftPoint(axialShiftCoefficient);
	mPoint3.shiftPoint(axialShiftCoefficient);
	mPoint4.shiftPoint(axialShiftCoefficient);
	mPoint5.shiftPoint(axialShiftCoefficient);
	mPoint6.shiftPoint(axialShiftCoefficient);
	mPoint7.shiftPoint(axialShiftCoefficient);
	mPoint8.shiftPoint(axialShiftCoefficient);
}

void Parallelepiped::scaleX(int scalingFactor) {
	mPoint1.scalePointX(scalingFactor);
	mPoint2.scalePointX(scalingFactor);
	mPoint3.scalePointX(scalingFactor);
	mPoint4.scalePointX(scalingFactor);
	mPoint5.scalePointX(scalingFactor);
	mPoint6.scalePointX(scalingFactor);
	mPoint7.scalePointX(scalingFactor);
	mPoint8.scalePointX(scalingFactor);
}

void Parallelepiped::scaleY(int scalingFactor) {
	mPoint1.scalePointY(scalingFactor);
	mPoint2.scalePointY(scalingFactor);
	mPoint3.scalePointY(scalingFactor);
	mPoint4.scalePointY(scalingFactor);
	mPoint5.scalePointY(scalingFactor);
	mPoint6.scalePointY(scalingFactor);
	mPoint7.scalePointY(scalingFactor);
	mPoint8.scalePointY(scalingFactor);
}

void Parallelepiped::scaleZ(int scalingFactor) {
	mPoint1.scalePointZ(scalingFactor);
	mPoint2.scalePointZ(scalingFactor);
	mPoint3.scalePointZ(scalingFactor);
	mPoint4.scalePointZ(scalingFactor);
	mPoint5.scalePointZ(scalingFactor);
	mPoint6.scalePointZ(scalingFactor);
	mPoint7.scalePointZ(scalingFactor);
	mPoint8.scalePointZ(scalingFactor);

}

void Parallelepiped::scale(int scalingFactor) {
	mPoint1.scalePoint(scalingFactor);
	mPoint2.scalePoint(scalingFactor);
	mPoint3.scalePoint(scalingFactor);
	mPoint4.scalePoint(scalingFactor);
	mPoint5.scalePoint(scalingFactor);
	mPoint6.scalePoint(scalingFactor);
	mPoint7.scalePoint(scalingFactor);
	mPoint8.scalePoint(scalingFactor);
}
