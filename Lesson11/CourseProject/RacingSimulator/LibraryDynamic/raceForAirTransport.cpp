#include "raceForAirTransport.h"

VehiclesDynamic::RaceForAirTranspot::RaceForAirTranspot() {

	this->name = "Гонка для воздушного транспорта";
}

VEHICLESLIBRARY_API bool VehiclesDynamic::RaceForAirTranspot::AddVehicle(Vehicle& vehicle) {

	bool VehicleIsNotAirTransportation = false;

	if (vehicle.getNameOfVehicle() == "Ботинки-вездеходы" || vehicle.getNameOfVehicle() == "Верблюд" || vehicle.getNameOfVehicle() == "Кентавр" || vehicle.getNameOfVehicle() == "Верблюд-быстроход") {
		VehicleIsNotAirTransportation = true;
		return  VehicleIsNotAirTransportation;
	}
	vehicle.counterOfVehicle++;
	vehicles.push_back(vehicle);
	
	return VehicleIsNotAirTransportation;
}
