#pragma once

#include "race.h"

namespace VehiclesDynamic {

	class RaceForAirTranspot : public Race {

	public:
		VEHICLESLIBRARY_API RaceForAirTranspot();
		VEHICLESLIBRARY_API bool AddVehicle(Vehicle* vehicle) override;
		VEHICLESLIBRARY_API double CalcTimeRide(Vehicle* vehicle)const;

	};

}