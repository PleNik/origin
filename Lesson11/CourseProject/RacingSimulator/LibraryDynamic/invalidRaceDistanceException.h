#pragma once

#include<iostream>

#include "vehicle.h"


namespace VehiclesDynamic {

	class InvalidRaceDistanceException : public std::exception {

	public:
		VEHICLESLIBRARY_API InvalidRaceDistanceException(const char* message);
	};

}
