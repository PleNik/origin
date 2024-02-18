#include "allTerrainBoots.h"

VehiclesDynamic::AllTerrainBoots::AllTerrainBoots() {

    speed = 6;
    drivingTimeBeforeRest = 60;
    counterOfAllTerrainBoots++;
    nameOfVehicle = "Ботинки-вездеходы";
    timeOfRace = distance / speed;

    if ((distance / speed) > drivingTimeBeforeRest)
    {
        for (int i = 1; i < ((distance / speed) / drivingTimeBeforeRest); i++) {

            if (i == 1) durationOfRest = 10;

            else durationOfRest = 5;

            timeOfRace += durationOfRest;
        }
    }
}

int VehiclesDynamic::AllTerrainBoots::counterOfAllTerrainBoots = 0; //инициализация статической переменной вне класса