#include "camel.h"

VehiclesDynamic::Camel::Camel() {

	speed = 10;
	drivingTimeBeforeRest = 30;
    nameOfVehicle = "Верблюд";
    counterOfCamel++;
    timeOfRace = distance / speed;

    if ((distance / speed) > drivingTimeBeforeRest) {

        for (int i = 1; i < ((distance / speed) / drivingTimeBeforeRest); i++) {

            if (i == 1) durationOfRest = 5;
            else durationOfRest = 8;

            timeOfRace += durationOfRest;
        }

    }
}

int VehiclesDynamic::Camel::counterOfCamel = 0;