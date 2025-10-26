#include "AllTerrainBoots.h"

namespace RaceSimulatorLibraryDynamic {
        SIMULATORLIBRARYDY_API AllTerrainBoots::AllTerrainBoots() {
            speed = 6.0;
            name = "Ботинки-вездеходы";
            travelTimeBeforeRest = 60.0;
            transportType = RaceSimulatorLibraryDynamic::TransportType::Ground;
        }

        SIMULATORLIBRARYDY_API double AllTerrainBoots:: RaceTime(double distance) {
            raceTime = distance / speed;
            if (distance / speed > travelTimeBeforeRest) {
                for (int i = 1; i < (distance / speed) / travelTimeBeforeRest; i++) {
                    if (i == 1) durationOfRest = 10;
                    else durationOfRest = 5;
                    raceTime += durationOfRest;
                }
            }
            return raceTime;
        }
}
