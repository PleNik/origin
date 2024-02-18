#include "eagle.h"
#include "magicCarpet.h"

VehiclesDynamic::Eagle::Eagle() {

    speed = 8;
    distanceReductionFactor = 6;
    counterOfEagle++;
    nameOfVehicle = "Орел";

    timeOfRace = (distance - distance * distanceReductionFactor / 100) / speed;
}

int VehiclesDynamic::Eagle::counterOfEagle = 0; //инициализация статической переменной вне класса