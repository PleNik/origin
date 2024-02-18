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

double VehiclesDynamic::Race::distance = 0;  //инициализация статической переменной вне класса
