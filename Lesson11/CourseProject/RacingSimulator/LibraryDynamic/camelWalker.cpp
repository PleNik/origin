#include "camelWalker.h"

VehiclesDynamic::CamelWalker::CamelWalker() {

	speed = 40;
	drivingTimeBeforeRest = 10;
	distance = distance;
    counterOfCamelWalker++;
    nameOfVehicle = "Верблюд-быстроход";
    timeOfRace = distance / speed;

    if ((distance / speed) > drivingTimeBeforeRest) {

        for (int i = 1; i < (raceTimeWithoutRest /
            drivingTimeBeforeRest); i++) {

            if (i == 1) durationOfRest = 5;
            else if (i == 3) durationOfRest = 6.5;
            else durationOfRest = 8;

            timeOfRace += durationOfRest;
        }

    }

}

int VehiclesDynamic::CamelWalker::counterOfCamelWalker = 0;