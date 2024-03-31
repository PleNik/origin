#pragma once

#include <vector>

#include "ITransport.h"

namespace RaceSimulatorLibraryDynamic {
    class Race {
    public:
        //SIMULATORLIBRARYDY_API double RaceTime(ITransport* transport);

        SIMULATORLIBRARYDY_API virtual bool AddTransport(RaceSimulatorLibraryDynamic::ITransport* transport);

        SIMULATORLIBRARYDY_API void SetDistance(double distance);

        SIMULATORLIBRARYDY_API std::vector<ITransport*> GetArrTransports();

        SIMULATORLIBRARYDY_API std::string& GetRaceType();

        SIMULATORLIBRARYDY_API double GetDistance();

        SIMULATORLIBRARYDY_API std::string GetNameRace();

    protected:
        std::string nameRace;
        double distance;
        std::vector<RaceSimulatorLibraryDynamic::ITransport*> transports;
    };
}
