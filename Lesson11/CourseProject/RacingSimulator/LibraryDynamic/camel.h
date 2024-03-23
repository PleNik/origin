#pragma once

#include "landVehicle.h"

namespace VehiclesDynamic {

    class Camel :public LandVehicle {
    public:
        VEHICLESLIBRARY_API Camel();

        static int  VEHICLESLIBRARY_API counterOfCamel;

        VEHICLESLIBRARY_API TransportType getType() const override;

        VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;

    };

    
}


