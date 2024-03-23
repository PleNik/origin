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
		VEHICLESLIBRARY_API TransportType getType() const override;//тип, чтобы выбирать в какой гонке будет участвовать
		VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;

	};

}