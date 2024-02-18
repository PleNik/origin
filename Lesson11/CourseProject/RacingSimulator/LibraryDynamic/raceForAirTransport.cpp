#include "raceForAirTransport.h"

VehiclesDynamic::RaceForAirTranspot::RaceForAirTranspot() {

	this->name = "����� ��� ���������� ����������";
}

VEHICLESLIBRARY_API bool VehiclesDynamic::RaceForAirTranspot::AddVehicle(Vehicle& vehicle) {

	bool VehicleIsNotAirTransportation = false;

	if (vehicle.getNameOfVehicle() == "�������-���������" || vehicle.getNameOfVehicle() == "�������" || vehicle.getNameOfVehicle() == "�������" || vehicle.getNameOfVehicle() == "�������-���������") {
		VehicleIsNotAirTransportation = true;
		return  VehicleIsNotAirTransportation;
	}
	vehicle.counterOfVehicle++;
	vehicles.push_back(vehicle);
	
	return VehicleIsNotAirTransportation;
}
