#include "magicCarpet.h"

VehiclesDynamic::MagicCarpet::MagicCarpet() {
	speed = 10;

	if (distance < 1000)
		distanceReductionFactor = 0;
	else if (distance >= 1000 && distance < 5000)
		distanceReductionFactor = 3;
	else if (distance >= 5000 && distance < 10000)
		distanceReductionFactor = 10;
	else
		distanceReductionFactor = 5;

	counterOfMagicCarpet++;
	nameOfVehicle = "Ковер-самолет";

	timeOfRace = (distance - distance * distanceReductionFactor / 100) / speed;
}

int VehiclesDynamic::MagicCarpet::counterOfMagicCarpet = 0; //инициализация статической переменной вне класса