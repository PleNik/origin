#pragma once

#include"vehicle.h"

namespace VehiclesDynamic {

	class AirVehicle : public Vehicle {

	protected:
		int distanceReductionFactor; //����������� ���������� ����������

	public:
		VEHICLESLIBRARY_API AirVehicle();
	};

}

