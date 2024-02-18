#pragma once

#include "race.h"

namespace VehiclesDynamic {

	class RaceForLandTransport : public Race {

	public:
		VEHICLESLIBRARY_API RaceForLandTransport();

		VEHICLESLIBRARY_API bool AddVehicle(Vehicle& vehicle) override;

	};
}
