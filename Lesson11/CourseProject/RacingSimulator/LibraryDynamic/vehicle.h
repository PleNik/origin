#pragma once

#include<iostream>
#include<vector>

#ifdef VEHICLESLIBRARYDYNAMIC_EXPORTS
#define VEHICLESLIBRARY_API __declspec(dllexport)
#else
#define VEHICLESLIBRARY_API __declspec(dllimport)
#endif //VEHICLESLIBRARYDYNAMIC_EXPORTS

namespace VehiclesDynamic {

    class Vehicle {

    protected:
        double speed; //скорость ТС
        std::string nameOfVehicle;
        double timeOfRace = 0;
         

    public:
        VEHICLESLIBRARY_API std::string getNameOfVehicle();
        VEHICLESLIBRARY_API double getTimeOfRace();

        VEHICLESLIBRARY_API static double distance;
        VEHICLESLIBRARY_API static int counterOfVehicle;
    };

}
