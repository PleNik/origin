#pragma once

#include "landVehicle.h"

namespace VehiclesDynamic {

    class AllTerrainBoots : public LandVehicle {
    public:
        VEHICLESLIBRARY_API AllTerrainBoots();
     
        VEHICLESLIBRARY_API static int counterOfAllTerrainBoots; //счетчик количества объектов класса
    };

}

