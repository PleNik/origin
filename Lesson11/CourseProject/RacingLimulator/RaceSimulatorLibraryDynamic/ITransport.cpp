#include "ITransport.h"

namespace RaceSimulatorLibraryDynamic {
   
    SIMULATORLIBRARYDY_API double ITransport::RaceTime (double distance){
        return 0.0;
    }

    SIMULATORLIBRARYDY_API std::string ITransport::GetNameTransport() {
        return name;
    }

    SIMULATORLIBRARYDY_API TransportType ITransport::GetTransportType() {
        return transportType;
    }
    
}


