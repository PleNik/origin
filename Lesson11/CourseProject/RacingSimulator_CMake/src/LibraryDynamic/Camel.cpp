#include "Camel.h"

namespace RaceSimulatorLibraryDynamic {
	SIMULATORLIBRARYDY_API double Camel::RaceTime(double distance) {
        raceTime = distance / speed;
        if (distance / speed > travelTimeBeforeRest) {
            for (int i = 1; i < (distance / speed) / travelTimeBeforeRest; i++) {
                if (i == 1)
                    durationOfRest = 5;
                else
                    durationOfRest = 8;
                raceTime += durationOfRest;
            }
        }
        return raceTime;
    }

    SIMULATORLIBRARYDY_API Camel::Camel() {
        speed = 10.0;
        name = "Верблюд";
        travelTimeBeforeRest = 30.0;
        transportType = RaceSimulatorLibraryDynamic::TransportType::Ground;
    }
}
