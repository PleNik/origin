#pragma once

#include "Camel.h"

namespace RaceSimulatorLibraryDynamic {
    class CamelFast : public Camel {
    public:
        SIMULATORLIBRARYDY_API CamelFast();

        SIMULATORLIBRARYDY_API double RaceTime(double distance) override;

    };
}
