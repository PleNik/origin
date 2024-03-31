#pragma once

#include "Race.h"

namespace RaceSimulatorLibraryDynamic {
    class LandRace : public Race {
    public:
        SIMULATORLIBRARYDY_API LandRace();

        SIMULATORLIBRARYDY_API bool AddTransport(RaceSimulatorLibraryDynamic::ITransport* transport) override;

    };
}