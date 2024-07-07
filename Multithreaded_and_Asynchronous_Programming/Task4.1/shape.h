#pragma once

#include<string>
#include<iostream>

#include"pointXY.h"
#include"pointXYZ.h"

class Shape {
public:
	Shape();

	virtual void print_info();

	virtual void shift(int axialShiftCoefficient);

	virtual void scaleX(int scalingFactor);

	virtual void scaleY(int scalingFactor);

	virtual void scaleZ(int scalingFactor);

	virtual void scale(int scalingFactor);

protected:
	std::string mName;
	/*class Point {
	public:
		Point() {}
		void setPoint(int aX, int aY) {
			mX = aX;
			mY = aY;
		}

		int getX()const { return mX;}
		int getY()const { return mY; }

		void shiftPoint(int axialShiftCoefficient) {
			mX += axialShiftCoefficient;
			mY += axialShiftCoefficient;
		}
		
		void scalePointX(int scalingFactor) {
			mX *= scalingFactor;
		}

		void scalePointY(int scalingFactor) {
			mY *= scalingFactor;
		}

		void scalePoint(int scalingFactor) {
			mX /= scalingFactor;
			mY /= scalingFactor;
		}
		
	protected:
		int mX{}; int mY{};
	};

	class Point_z : public Point {
	public:
		void setPoint(int aZ) {
			mZ = aZ;
		}

		int getZ()const { return mZ; }

		void shiftPoint_z(int axialShiftCoefficient) {
			mZ += axialShiftCoefficient;
		}

		void scalePoint_zZ(int scalingFactor) {
			mZ *= scalingFactor;
		}

		void scalePointZ(int scalingFactor) {
			mZ /= scalingFactor;
		}

	protected:
		int mZ{};
	};*/

};
