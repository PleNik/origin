#include "vehicle.h"


VEHICLESLIBRARY_API std::string VehiclesDynamic::Vehicle::getNameOfVehicle()
{
    return nameOfVehicle;
}

VEHICLESLIBRARY_API VehiclesDynamic::TransportType VehiclesDynamic::Vehicle::getType() const
{
    return transportType;
}

VEHICLESLIBRARY_API double VehiclesDynamic::Vehicle::CalcTimeRide(double distance) const {
   return 0.0;
}
