#pragma once

#include "airVehicle.h"

namespace VehiclesDynamic {

	class Eagle : public AirVehicle {
	public:
		VEHICLESLIBRARY_API Eagle();
		
		VEHICLESLIBRARY_API static int counterOfEagle; //������� ���������� �������� ������

		VEHICLESLIBRARY_API TransportType getType() const override;

		VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;
	};
}
