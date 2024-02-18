#pragma once

#include"vehicle.h"

namespace VehiclesDynamic {
	class LandVehicle : public Vehicle {
	protected:
		double drivingTimeBeforeRest; //����� �������� �� ������
		double durationOfRest; //������������ ������
		double raceTimeWithoutRest; //����� ����� ��� ������

	public:
		VEHICLESLIBRARY_API LandVehicle();
	};

}
