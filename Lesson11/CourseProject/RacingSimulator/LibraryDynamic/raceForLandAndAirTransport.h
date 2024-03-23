#pragma once

#include "race.h"

namespace VehiclesDynamic {

	class RaceForLandAndAirTransport : public Race {
	public:
		VEHICLESLIBRARY_API RaceForLandAndAirTransport();
		VEHICLESLIBRARY_API bool AddVehicle(Vehicle* vehicle) override;
		VEHICLESLIBRARY_API double CalcTimeRide(Vehicle* vehicle) const;
	};
}