#pragma once

#include "airVehicle.h"

namespace VehiclesDynamic {

	class MagicCarpet : public AirVehicle {

	public:
		VEHICLESLIBRARY_API MagicCarpet();
		VEHICLESLIBRARY_API static int counterOfMagicCarpet; //счетчик количества объектов класса

		VEHICLESLIBRARY_API TransportType getType() const override;

		VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;
	};


}

