#pragma once

#include "landVehicle.h"

namespace VehiclesDynamic {

    class AllTerrainBoots : public LandVehicle {
    public:
        VEHICLESLIBRARY_API AllTerrainBoots();
     
        VEHICLESLIBRARY_API static int counterOfAllTerrainBoots; //������� ���������� �������� ������

        VEHICLESLIBRARY_API TransportType getType() const override {//���, ����� �������� � ����� ����� ����� �����������
            return TransportType::Ground;
        }

        VEHICLESLIBRARY_API double CalcTimeRide(double distance) const override;
    };



}

