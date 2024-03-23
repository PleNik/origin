#include "raceForAirTransport.h"

VehiclesDynamic::RaceForAirTranspot::RaceForAirTranspot() {

	this->name = "Гонка для воздушного транспорта";
}

VEHICLESLIBRARY_API bool VehiclesDynamic::RaceForAirTranspot::AddVehicle(Vehicle* vehicle) {

	bool VehicleIsNotAirTransportation = false;

	if (vehicle->getType() != TransportType::Air) {
		VehicleIsNotAirTransportation = true;
		return  VehicleIsNotAirTransportation;
	}
	vehicles.push_back(vehicle);
	
	return VehicleIsNotAirTransportation;
}

VEHICLESLIBRARY_API double VehiclesDynamic::RaceForAirTranspot::CalcTimeRide(Vehicle* vehicle) const {

	return Race::CalcTimeRide(vehicle);
}


