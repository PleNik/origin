#include "centaur.h"

VehiclesDynamic::Centaur::Centaur() {

    speed = 15;
    drivingTimeBeforeRest = 8;
    durationOfRest = 2;
    counterOfCentaur++;
    nameOfVehicle = "Кентавр";
    timeOfRace = distance / speed;

    if  ((distance / speed) > drivingTimeBeforeRest) {

        for (int i = 1; i < ((distance / speed) / drivingTimeBeforeRest); i++) {

            timeOfRace += durationOfRest;
        }

    }

}

int VehiclesDynamic::Centaur::counterOfCentaur = 0;