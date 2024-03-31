#pragma once

#include<iostream>

#include"Enums.h"

#ifdef RACESIMULATORLIBRARYDYNAMIC_EXPORTS
#define SIMULATORLIBRARYDY_API __declspec(dllexport)
#else
#define SIMULATORLIBRARYDY_API __declspec(dllimport)
#endif // RACESIMULATORLIBRARYDYNAMIC_EXPORTS

namespace RaceSimulatorLibraryDynamic {
    class ITransport {
    public:
        SIMULATORLIBRARYDY_API virtual double RaceTime(double distance);

        SIMULATORLIBRARYDY_API std::string GetNameTransport();
    
        SIMULATORLIBRARYDY_API TransportType GetTransportType();

    protected:
        std::string name;
        double speed;
        TransportType transportType;
        double raceTime;
    };
}