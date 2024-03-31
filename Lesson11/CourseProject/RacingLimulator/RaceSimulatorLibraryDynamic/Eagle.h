#pragma once

#include"AirTransport.h"

namespace RaceSimulatorLibraryDynamic {
    class Eagle : public AirTransport {
    public:
        SIMULATORLIBRARYDY_API Eagle();

        SIMULATORLIBRARYDY_API double RaceTime(double distance) override;
    };
}
