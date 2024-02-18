#include "broom.h"

VehiclesDynamic::Broom::Broom() {
	speed = 20;
	distanceReductionFactor = distance / 1000;
	counterOfBroom++;
	nameOfVehicle = "Метла";

	timeOfRace = (distance - distance * distanceReductionFactor / 100) / speed;
}


int VehiclesDynamic::Broom::counterOfBroom = 0; //инициализация статической переменной вне класса