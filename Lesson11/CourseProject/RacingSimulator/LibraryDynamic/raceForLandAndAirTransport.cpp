#include "raceForLandAndAirTransport.h"

VehiclesDynamic::RaceForLandAndAirTransport::RaceForLandAndAirTransport() {

	this->name = "����� ��� ��������� � ���������� ����������";
}

VEHICLESLIBRARY_API bool VehiclesDynamic::RaceForLandAndAirTransport::AddVehicle(Vehicle& vehicle)
{
	vehicle.counterOfVehicle++;
	vehicles.push_back(vehicle);
	
	return false;
}
