#pragma once

class PointXY {
public:
	PointXY();
	void setPoint(int aX, int aY);

	int getX() const;
	int getY() const;

	void shiftPoint(int axialShiftCoefficien);
	void scalePointX(int scalingFactor);
	void scalePointY(int scalingFactor);
	void scalePoint(int scalingFactor);

protected:
	int mX{};
	int mY{};
};