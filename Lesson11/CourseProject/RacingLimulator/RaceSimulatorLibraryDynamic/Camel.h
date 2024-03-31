#pragma once

#include "GroundTransport.h"

namespace RaceSimulatorLibraryDynamic {
    class Camel : public GroundTransport {
    public:
        SIMULATORLIBRARYDY_API Camel();

        SIMULATORLIBRARYDY_API double RaceTime(double distance) override;
    };
}
