#include "AirRace.h"

namespace RaceSimulatorLibraryDynamic {
    SIMULATORLIBRARYDY_API AirRace::AirRace() {
        nameRace = "Гонка для воздушного транспорта";
    }

    SIMULATORLIBRARYDY_API bool AirRace::AddTransport(ITransport* transport) {
        bool isNotAirTransport = false;
        if (transport->GetTransportType() != TransportType::Air) {
            isNotAirTransport = true;
            return isNotAirTransport;
        }

        transports.push_back(transport);
        return isNotAirTransport;
    }
}