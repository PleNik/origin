#pragma once

#include"vehicle.h"

namespace VehiclesDynamic {

	class AirVehicle : public Vehicle {

	protected:
		int distanceReductionFactor; //коэффициент сокращения расстояния

	public:
		VEHICLESLIBRARY_API AirVehicle();

		VEHICLESLIBRARY_API TransportType getType() const override;

		VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;

	};

}

