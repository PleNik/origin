#pragma once

#include "GroundTransport.h"


namespace RaceSimulatorLibraryDynamic {
    class Centaur : public GroundTransport {
    public:
        SIMULATORLIBRARYDY_API Centaur();

        SIMULATORLIBRARYDY_API double RaceTime(double distance) override;
    };
}
