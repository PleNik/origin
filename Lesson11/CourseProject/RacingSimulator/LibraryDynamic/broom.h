#pragma once

#include "airVehicle.h"

namespace VehiclesDynamic {

	class Broom : public AirVehicle {

	public:
		VEHICLESLIBRARY_API Broom();
	
		VEHICLESLIBRARY_API static int counterOfBroom; //счетчик количества объектов класса

		VEHICLESLIBRARY_API TransportType getType() const override;

		VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;
	};

}