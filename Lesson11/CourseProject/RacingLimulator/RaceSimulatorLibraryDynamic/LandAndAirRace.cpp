#include "LandAndAirRace.h"

namespace RaceSimulatorLibraryDynamic {
    SIMULATORLIBRARYDY_API LandAndAirRace::LandAndAirRace() {
        nameRace = "√онка дл€ наземного и воздушного транспорта";
    }

    SIMULATORLIBRARYDY_API bool LandAndAirRace::AddTransport(RaceSimulatorLibraryDynamic::ITransport* transport) {
        transports.push_back(transport);
        return false;
    }
}