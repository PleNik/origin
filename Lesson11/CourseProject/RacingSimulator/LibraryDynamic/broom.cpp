#include "broom.h"

VehiclesDynamic::Broom::Broom() {
	speed = 20;
	counterOfBroom++;
	nameOfVehicle = "�����";

}

VEHICLESLIBRARY_API VehiclesDynamic::TransportType VehiclesDynamic::Broom::getType() const {
	return transportType;
}

VEHICLESLIBRARY_API double VehiclesDynamic::Broom::CalcTimeRide(double distance) const {
	

	return (distance - distance * distance / 10) / speed;
}

int VehiclesDynamic::Broom::counterOfBroom = 0; //������������� ����������� ���������� ��� ������