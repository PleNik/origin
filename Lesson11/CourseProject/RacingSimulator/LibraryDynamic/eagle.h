#pragma once

#include "airVehicle.h"

namespace VehiclesDynamic {

	class Eagle : public AirVehicle {
	public:
		VEHICLESLIBRARY_API Eagle();
		
		VEHICLESLIBRARY_API static int counterOfEagle; //счетчик количества объектов класса
	};
}
