#pragma once

#include "race.h"

namespace VehiclesDynamic {

	class RaceForLandAndAirTransport : public Race {
	public:
		VEHICLESLIBRARY_API RaceForLandAndAirTransport();
		VEHICLESLIBRARY_API bool AddVehicle(Vehicle& vehicle) override;
	};
}