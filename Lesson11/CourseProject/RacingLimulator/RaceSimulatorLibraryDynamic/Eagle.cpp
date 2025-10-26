#include"Eagle.h"

namespace RaceSimulatorLibraryDynamic {
    SIMULATORLIBRARYDY_API Eagle::Eagle() {
        speed = 8.0;
        name = "iagle";
        transportType = RaceSimulatorLibraryDynamic::TransportType::Air;
        distanceReductionFactor = 6;
    }

    SIMULATORLIBRARYDY_API double Eagle::RaceTime(double distance) {
        return (distance - distance * distanceReductionFactor / 100) / speed;
    }
}
