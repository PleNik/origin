#pragma once

#include "camel.h"

namespace VehiclesDynamic {

    class CamelWalker : public Camel {
    public:
        VEHICLESLIBRARY_API CamelWalker();
 
        VEHICLESLIBRARY_API static int counterOfCamelWalker;

        VEHICLESLIBRARY_API TransportType getType() const override;

        VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;
    };
}

