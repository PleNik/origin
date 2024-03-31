#pragma once

#include"AirTransport.h"

namespace RaceSimulatorLibraryDynamic {
    class CarpetPlane : public AirTransport {
    public:
        SIMULATORLIBRARYDY_API CarpetPlane();

        SIMULATORLIBRARYDY_API double RaceTime(double distance) override;
    };
}