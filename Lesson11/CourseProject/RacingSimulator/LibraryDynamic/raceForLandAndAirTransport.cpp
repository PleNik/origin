#include "raceForLandAndAirTransport.h"

VehiclesDynamic::RaceForLandAndAirTransport::RaceForLandAndAirTransport() {

	this->name = "√онка дл€ наземного и воздушного транспорта";
}

VEHICLESLIBRARY_API bool VehiclesDynamic::RaceForLandAndAirTransport::AddVehicle(Vehicle* vehicle)
{
	vehicles.push_back(vehicle);
	
	return false;
}

VEHICLESLIBRARY_API double VehiclesDynamic::RaceForLandAndAirTransport::CalcTimeRide(Vehicle* vehicle) const
{
	return Race::CalcTimeRide(vehicle);
}
