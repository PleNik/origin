#pragma once

#include<iostream>

#include "vehicle.h"


namespace VehiclesDynamic {

    class InvalidTypeException : public std::domain_error {

    public:
        VEHICLESLIBRARY_API InvalidTypeException(const char* message);
    };
}
