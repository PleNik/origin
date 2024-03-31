#pragma once

#include"AirTransport.h"

namespace RaceSimulatorLibraryDynamic {
    class Broom : public AirTransport{
    public:
        SIMULATORLIBRARYDY_API Broom();

        SIMULATORLIBRARYDY_API double RaceTime(double distance) override;
    };
}
