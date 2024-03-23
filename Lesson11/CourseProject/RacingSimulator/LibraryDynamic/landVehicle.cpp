#include "landVehicle.h"

VehiclesDynamic::LandVehicle::LandVehicle() {

	nameOfVehicle = "Наземное транспортное средство";
	transportType = TransportType::Ground;
}

VEHICLESLIBRARY_API VehiclesDynamic::TransportType VehiclesDynamic::LandVehicle::getType() const
{
	return transportType;
}


VEHICLESLIBRARY_API double VehiclesDynamic::LandVehicle::CalcTimeRide(double distance) const {
	return 0.0;
}
