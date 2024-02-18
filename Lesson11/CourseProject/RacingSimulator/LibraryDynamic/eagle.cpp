#include "eagle.h"
#include "magicCarpet.h"

VehiclesDynamic::Eagle::Eagle() {

    speed = 8;
    distanceReductionFactor = 6;
    counterOfEagle++;
    nameOfVehicle = "����";

    timeOfRace = (distance - distance * distanceReductionFactor / 100) / speed;
}

int VehiclesDynamic::Eagle::counterOfEagle = 0; //������������� ����������� ���������� ��� ������