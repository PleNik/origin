#pragma once

#include"vehicle.h"

namespace VehiclesDynamic {
	class LandVehicle : public Vehicle {
	protected:
		double drivingTimeBeforeRest; //время движения до отдыха
		double durationOfRest; //длительность отдыха
		double raceTimeWithoutRest; //время гонки без отдыха

	public:
		VEHICLESLIBRARY_API LandVehicle();
	};

}
