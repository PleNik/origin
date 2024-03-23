#include "airVehicle.h"

VehiclesDynamic::AirVehicle::AirVehicle() {

	nameOfVehicle = "Воздушное транспортное средство";
	distanceReductionFactor = 0;
	transportType = TransportType::Air;
}

VEHICLESLIBRARY_API VehiclesDynamic::TransportType VehiclesDynamic::AirVehicle::getType() const
{
	return transportType;
}

VEHICLESLIBRARY_API double VehiclesDynamic::AirVehicle::CalcTimeRide(double distance) const {
	return 0.0;
}
