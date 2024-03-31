#pragma once

#include "Race.h"

namespace RaceSimulatorLibraryDynamic {
    class LandAndAirRace : public Race {
    public:
        SIMULATORLIBRARYDY_API LandAndAirRace();

        SIMULATORLIBRARYDY_API bool AddTransport(RaceSimulatorLibraryDynamic::ITransport* transport) override;
    };
}
