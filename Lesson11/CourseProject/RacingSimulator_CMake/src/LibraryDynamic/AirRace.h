#pragma once

#include "Race.h"

namespace RaceSimulatorLibraryDynamic {
    class AirRace : public Race {
    public:
        SIMULATORLIBRARYDY_API AirRace();

        SIMULATORLIBRARYDY_API bool AddTransport(ITransport* transport) override;
    };
}