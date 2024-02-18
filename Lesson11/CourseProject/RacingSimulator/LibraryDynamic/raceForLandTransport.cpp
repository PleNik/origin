#include "raceForLandTransport.h"

VehiclesDynamic::RaceForLandTransport::RaceForLandTransport() {

	this->name = "Гонка для наземного транспорта";
}


bool VehiclesDynamic::RaceForLandTransport::AddVehicle(Vehicle& vehicle) {

	bool VehicleIsNotGroundTransportation = false;
	if (vehicle.getNameOfVehicle() == "Ковер-самолет" || vehicle.getNameOfVehicle() == "Орел" || vehicle.getNameOfVehicle() == "Метла") {
		
		VehicleIsNotGroundTransportation = true;

		return  VehicleIsNotGroundTransportation;
	}

	vehicle.counterOfVehicle ++;
	vehicles.push_back(vehicle);

	return VehicleIsNotGroundTransportation;
}

