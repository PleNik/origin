#pragma once

#include "enumRace.h"
#include "enumMenu.h"
#include "enumVehicle.h"
#include "enumOneMoreRaceOrExit.h" 
#include "invalidTypeException.h"
#include "invalidRaceDistanceException.h"

//�������� �� ����������: ������� ��������� �������� ����� �����
void checkUserInputRace(VehiclesDynamic::RaceType& userInput);

//�������� �� ����������: ������� ��������� �������� ���������
void checkUserInputDistance(double distance);

//�������� �� ����������: ������� ��������� �������� ������� ����
void checkUserInputMenu(VehiclesDynamic::Menu& userInput);

//��������� �� ����������: ������� ��������� �������� ������ ��
void checkUserInputVehicleType(VehiclesDynamic::VehicleType& userInput);

//�������� �� ����������: ������� ��������� �������� ������ �������: ��� ���� �����/�����
void checkUserInputOneMoreRaceOrExit(VehiclesDynamic::OneMoreRaceOrExit& userInput);