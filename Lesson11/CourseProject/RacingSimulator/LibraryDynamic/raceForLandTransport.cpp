#include "raceForLandTransport.h"

VehiclesDynamic::RaceForLandTransport::RaceForLandTransport() {

	this->name = "Гонка для наземного транспорта";
}


bool VehiclesDynamic::RaceForLandTransport::AddVehicle(Vehicle* vehicle) {

	bool VehicleIsNotGroundTransportation = false;
	
	if (vehicle->getType() != TransportType::Ground) {
		
		VehicleIsNotGroundTransportation = true;

		return  VehicleIsNotGroundTransportation;
	}

	vehicles.push_back(vehicle);

	return VehicleIsNotGroundTransportation;
}

VEHICLESLIBRARY_API double VehiclesDynamic::RaceForLandTransport::CalcTimeRide(Vehicle* vehicle) const
{
	return Race::CalcTimeRide(vehicle);
}



