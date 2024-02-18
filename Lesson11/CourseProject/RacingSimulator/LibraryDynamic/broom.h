#pragma once

#include "airVehicle.h"

namespace VehiclesDynamic {

	class Broom : public AirVehicle {

	public:
		VEHICLESLIBRARY_API Broom();
	
		VEHICLESLIBRARY_API static int counterOfBroom; //счетчик количества объектов класса
	};

}
