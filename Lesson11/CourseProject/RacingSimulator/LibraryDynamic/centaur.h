#pragma once

#include "landVehicle.h"

namespace VehiclesDynamic {

    class Centaur : public LandVehicle {
    public:
        VEHICLESLIBRARY_API Centaur();
    
        VEHICLESLIBRARY_API static int counterOfCentaur;

        VEHICLESLIBRARY_API TransportType getType() const override;

        VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;
    };
}


