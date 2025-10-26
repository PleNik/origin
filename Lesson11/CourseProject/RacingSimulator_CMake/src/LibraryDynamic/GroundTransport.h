#pragma once

#include"ITransport.h"

namespace RaceSimulatorLibraryDynamic {

    class GroundTransport : public ITransport {
    protected:
        double travelTimeBeforeRest; //время движения до отдыха
        double durationOfRest; //время отдыха

    };
}
