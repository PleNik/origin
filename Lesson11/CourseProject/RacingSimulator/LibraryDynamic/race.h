#pragma once

#include "camelWalker.h"
#include "enumVehicle.h"

namespace VehiclesDynamic {

	class Race {

	protected:
		std::string name; //наименование гонки
		int numberOfVehiclesInTheRace; //количество ТС, зарегистрированных на гонку
		double distance;

	public:
		//VEHICLESLIBRARY_API Race();
		VEHICLESLIBRARY_API void SetDistance(double distance);
		VEHICLESLIBRARY_API std::string GetName();
		VEHICLESLIBRARY_API double GetDistance();
		VEHICLESLIBRARY_API double CalcTimeRide(Vehicle* vehicle) const;

		//VEHICLESLIBRARY_API static double distance;

		VEHICLESLIBRARY_API bool virtual AddVehicle(Vehicle* vehicle);

		std::vector<VehiclesDynamic::Vehicle*> vehicles;



	};



}
