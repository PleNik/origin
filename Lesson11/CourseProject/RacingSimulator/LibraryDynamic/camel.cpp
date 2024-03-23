#include "camel.h"

VehiclesDynamic::Camel::Camel() {

	speed = 10;
	drivingTimeBeforeRest = 30;
    nameOfVehicle = "Верблюд";
    counterOfCamel++;

}

VEHICLESLIBRARY_API VehiclesDynamic::TransportType VehiclesDynamic::Camel::getType() const {

    return transportType;
}
 VEHICLESLIBRARY_API double VehiclesDynamic::Camel::CalcTimeRide(double distance) const {
     double durationOfRest;
     double timeOfRace = distance / speed;
     if ((distance / speed) > drivingTimeBeforeRest) {
         for (int i = 1; i < ((distance / speed) / drivingTimeBeforeRest); i++) {
             if (i == 1)
                 durationOfRest = 5;
             else durationOfRest = 8;

             timeOfRace += durationOfRest;
         }
     }

    return  timeOfRace;
 }

int VehiclesDynamic::Camel::counterOfCamel = 0;