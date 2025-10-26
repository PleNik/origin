#include"Broom.h"

namespace RaceSimulatorLibraryDynamic {
    SIMULATORLIBRARYDY_API Broom::Broom() {
        speed = 20.0;
        name = "Метла";
        transportType = RaceSimulatorLibraryDynamic::TransportType::Air;
    }

    SIMULATORLIBRARYDY_API double Broom::RaceTime(double distance) {
        distanceReductionFactor = static_cast<int>(distance) / 1000;
        return (distance - distance * distanceReductionFactor / 100) / speed;
    }
}
