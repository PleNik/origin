#pragma once

#include "airVehicle.h"

namespace VehiclesDynamic {

	class MagicCarpet : public AirVehicle {

	public:
		VEHICLESLIBRARY_API MagicCarpet();
		VEHICLESLIBRARY_API static int counterOfMagicCarpet; //счетчик количества объектов класса
	};

}

