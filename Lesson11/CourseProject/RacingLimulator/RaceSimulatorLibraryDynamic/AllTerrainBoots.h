#pragma once

#include "GroundTransport.h"

namespace RaceSimulatorLibraryDynamic {
    class AllTerrainBoots : public GroundTransport {
    public:
        SIMULATORLIBRARYDY_API AllTerrainBoots();


        SIMULATORLIBRARYDY_API double RaceTime(double distance) override;

    };
}