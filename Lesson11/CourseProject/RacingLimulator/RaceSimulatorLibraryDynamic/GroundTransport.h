#pragma once

#include"ITransport.h"

namespace RaceSimulatorLibraryDynamic {

    class GroundTransport : public ITransport {
    protected:
        double travelTimeBeforeRest; //����� �������� �� ������
        double durationOfRest; //����� ������

    };
}
