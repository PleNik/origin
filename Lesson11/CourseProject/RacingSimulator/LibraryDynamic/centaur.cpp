#include "centaur.h"

VehiclesDynamic::Centaur::Centaur() {

    speed = 15;
    drivingTimeBeforeRest = 8;
    durationOfRest = 2;
    counterOfCentaur++;
    nameOfVehicle = "Кентавр";
    
}

VEHICLESLIBRARY_API VehiclesDynamic::TransportType VehiclesDynamic::Centaur::getType() const {
    return transportType;
}

VEHICLESLIBRARY_API double VehiclesDynamic::Centaur::CalcTimeRide(double distance) const {

    double timeOfRace = distance / speed;
    if ((distance / speed) > drivingTimeBeforeRest) {

        for (int i = 1; i < ((distance / speed) / drivingTimeBeforeRest); i++) {

            timeOfRace += durationOfRest;
        }

    }
    return timeOfRace;
}

int VehiclesDynamic::Centaur::counterOfCentaur = 0;