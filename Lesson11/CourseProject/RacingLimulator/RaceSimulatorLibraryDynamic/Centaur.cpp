#include "Centaur.h"

namespace RaceSimulatorLibraryDynamic {
    SIMULATORLIBRARYDY_API Centaur::Centaur () {
        speed = 15.0;
        name = "Кентавр";
        travelTimeBeforeRest = 8.0;
        transportType = RaceSimulatorLibraryDynamic::TransportType::Ground;
        durationOfRest = 2;
    }

    SIMULATORLIBRARYDY_API double Centaur::RaceTime(double distance) {
        raceTime = distance / speed;
        if (distance / speed > travelTimeBeforeRest) {
            for (int i = 1; i < (distance / speed) / travelTimeBeforeRest; i++)
                raceTime += durationOfRest;
        }
        return raceTime;
    }
}