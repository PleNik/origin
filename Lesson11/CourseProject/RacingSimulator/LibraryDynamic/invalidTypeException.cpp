#include "invalidTypeException.h"

VehiclesDynamic::InvalidTypeException::InvalidTypeException(const char* message): domain_error(message) {}

