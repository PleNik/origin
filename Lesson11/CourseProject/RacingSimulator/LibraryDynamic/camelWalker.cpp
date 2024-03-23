#include "camelWalker.h"

VehiclesDynamic::CamelWalker::CamelWalker() {

	speed = 40;
	drivingTimeBeforeRest = 10;
	//distance;
    counterOfCamelWalker++;
    nameOfVehicle = "Верблюд-быстроход";
   
}

VEHICLESLIBRARY_API VehiclesDynamic::TransportType VehiclesDynamic::CamelWalker::getType() const {

    return transportType;
}

VEHICLESLIBRARY_API double VehiclesDynamic::CamelWalker::CalcTimeRide(double distance) const {
   double timeOfRace = distance / speed;
   double durationOfRest;

   if ((distance / speed) > drivingTimeBeforeRest) {

       for (int i = 1; i < ((distance / speed) / drivingTimeBeforeRest); i++) {

           if (i == 1) durationOfRest = 5;
           else if (i == 3) durationOfRest = 6.5;
           else durationOfRest = 8;

           timeOfRace += durationOfRest;
       }

   }
    return timeOfRace;
}

int VehiclesDynamic::CamelWalker::counterOfCamelWalker = 0;