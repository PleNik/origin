#include "eagle.h"
#include "magicCarpet.h"

VehiclesDynamic::Eagle::Eagle() {

    speed = 8;
    distanceReductionFactor = 6;
    counterOfEagle++;
    nameOfVehicle = "Орел";

}

VEHICLESLIBRARY_API VehiclesDynamic::TransportType VehiclesDynamic::Eagle::getType() const {

    return transportType;
}

VEHICLESLIBRARY_API double VehiclesDynamic::Eagle::CalcTimeRide(double distance) const {

    return  (distance - distance * distanceReductionFactor / 100) / speed;
}

int VehiclesDynamic::Eagle::counterOfEagle = 0; //инициализация статической переменной вне класса