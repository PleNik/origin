#include "CamelFast.h"

namespace RaceSimulatorLibraryDynamic {
    SIMULATORLIBRARYDY_API CamelFast::CamelFast() {
        speed = 40.0;
        name = "Верблюд-быстроход";
        travelTimeBeforeRest = 10.0;
        transportType = RaceSimulatorLibraryDynamic::TransportType::Ground;
    }

    SIMULATORLIBRARYDY_API double CamelFast::RaceTime(double distance) {
        raceTime = distance / speed;
        if (distance / speed > travelTimeBeforeRest) {
            for (int i = 1; i < (distance / speed) / travelTimeBeforeRest; i++) {
                if (i == 1) durationOfRest = 5;
                else if (i == 2) durationOfRest = 6.5;
                else durationOfRest = 8;

                raceTime += durationOfRest;
            }
        }
        return raceTime;
    }
}