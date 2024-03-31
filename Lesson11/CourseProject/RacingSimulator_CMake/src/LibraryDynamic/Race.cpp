#include "Race.h"

namespace RaceSimulatorLibraryDynamic {
   /* SIMULATORLIBRARYDY_API double Race::RaceTime(ITransport* transport) {
        return transport->RaceTime(distance);
    }*/

    SIMULATORLIBRARYDY_API bool Race::AddTransport(RaceSimulatorLibraryDynamic::ITransport* transport) {
        return false;
    }

    SIMULATORLIBRARYDY_API void Race::SetDistance(double distance) {
        this->distance = distance;
    }

    SIMULATORLIBRARYDY_API std::vector<ITransport*> Race::GetArrTransports() {
        return transports;
    }

    SIMULATORLIBRARYDY_API std::string& Race::GetRaceType() {
        return nameRace;
    }

    SIMULATORLIBRARYDY_API double Race::GetDistance() {
        return distance;
    }

    SIMULATORLIBRARYDY_API std::string Race::GetNameRace() {
        return nameRace;
    }
}
