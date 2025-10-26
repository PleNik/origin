#include"CarpetPlane.h"

namespace RaceSimulatorLibraryDynamic {
    SIMULATORLIBRARYDY_API CarpetPlane::CarpetPlane() {
        speed = 10.0;
        name = "carpetPlane";
        transportType = RaceSimulatorLibraryDynamic::TransportType::Air;
    }

    SIMULATORLIBRARYDY_API double CarpetPlane::RaceTime(double distance) {

        if (distance < 1000)
            distanceReductionFactor = 0;
        else if (distance >= 1000 && distance < 5000)
            distanceReductionFactor = 3;
        else if (distance >= 5000 && distance < 10000)
            distanceReductionFactor = 10;
        else
            distanceReductionFactor = 5;

        return (distance - distance * distanceReductionFactor / 100) / speed;
    }
}
