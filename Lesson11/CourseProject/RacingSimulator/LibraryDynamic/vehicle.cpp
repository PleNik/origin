#include "vehicle.h"


VEHICLESLIBRARY_API std::string VehiclesDynamic::Vehicle::getNameOfVehicle()
{
    return this->nameOfVehicle;
}

VEHICLESLIBRARY_API double VehiclesDynamic::Vehicle::getTimeOfRace()
{
    return timeOfRace;
}

//инициализация статических переменных вне класса
double VehiclesDynamic::Vehicle::distance = 0;  
int VehiclesDynamic::Vehicle::counterOfVehicle = 0;
