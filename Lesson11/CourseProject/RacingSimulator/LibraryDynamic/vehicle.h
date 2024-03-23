#pragma once

#include<iostream>
#include<vector>

#ifdef VEHICLESLIBRARYDYNAMIC_EXPORTS
#define VEHICLESLIBRARY_API __declspec(dllexport)
#else
#define VEHICLESLIBRARY_API __declspec(dllimport)
#endif //VEHICLESLIBRARYDYNAMIC_EXPORTS

namespace VehiclesDynamic {

    enum class TransportType {
        Ground,
        Air
    };

    class Vehicle {

    protected:
        double speed;
        std::string nameOfVehicle;
        //double timeOfRace = 0;
        TransportType transportType;
        double distance;
         

    public:
        VEHICLESLIBRARY_API std::string getNameOfVehicle();

        VEHICLESLIBRARY_API virtual TransportType getType() const;  //тип, чтобы выбирать в какой гонке будет участвовать

        VEHICLESLIBRARY_API virtual double CalcTimeRide(double distance) const; //расчёт времени по дистанции, математическая модель из ТЗ
    };

}
