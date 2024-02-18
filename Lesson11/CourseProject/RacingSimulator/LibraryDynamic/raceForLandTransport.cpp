#include "raceForLandTransport.h"

VehiclesDynamic::RaceForLandTransport::RaceForLandTransport() {

	this->name = "����� ��� ��������� ����������";
}


bool VehiclesDynamic::RaceForLandTransport::AddVehicle(Vehicle& vehicle) {

	bool VehicleIsNotGroundTransportation = false;
	if (vehicle.getNameOfVehicle() == "�����-�������" || vehicle.getNameOfVehicle() == "����" || vehicle.getNameOfVehicle() == "�����") {
		
		VehicleIsNotGroundTransportation = true;

		return  VehicleIsNotGroundTransportation;
	}

	vehicle.counterOfVehicle ++;
	vehicles.push_back(vehicle);

	return VehicleIsNotGroundTransportation;
}

