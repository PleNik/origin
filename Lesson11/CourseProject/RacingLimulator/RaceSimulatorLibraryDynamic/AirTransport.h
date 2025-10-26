#pragma once

#include"ITransport.h"

namespace RaceSimulatorLibraryDynamic {
    class AirTransport : public ITransport {        
    protected:
        int distanceReductionFactor;  //коэффициент сокращения расстояния
    };

}
