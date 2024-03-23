#include "race.h"


VEHICLESLIBRARY_API void VehiclesDynamic::Race::SetDistance(double distance) {

	this->distance = distance;
}

VEHICLESLIBRARY_API std::string VehiclesDynamic::Race::GetName()
{
	return this->name;
}

VEHICLESLIBRARY_API double VehiclesDynamic::Race::GetDistance()
{
	return this->distance;
}

VEHICLESLIBRARY_API double VehiclesDynamic::Race::CalcTimeRide(Vehicle* vehicle) const {

	return vehicle->CalcTimeRide(distance);
}

VEHICLESLIBRARY_API bool VehiclesDynamic::Race::AddVehicle(Vehicle* vehicle)
{
	return false;
}
