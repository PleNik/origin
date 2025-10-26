#include "LandRace.h"

namespace RaceSimulatorLibraryDynamic {
    SIMULATORLIBRARYDY_API LandRace::LandRace() {
        nameRace = "Гонка для наземного транспорта";
    }

    SIMULATORLIBRARYDY_API bool LandRace::AddTransport(ITransport* transport) {
        bool isNotLandTransport = false;
        if (transport->GetTransportType() != TransportType::Ground) {
            isNotLandTransport = true;
            return isNotLandTransport;
        }
        
        transports.push_back(transport);
        return isNotLandTransport;
    }
}
