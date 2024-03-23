#pragma once

#include "camelWalker.h"
#include "centaur.h"
#include "allTerrainBoots.h"
#include "magicCarpet.h"
#include "eagle.h"
#include "broom.h"
#include "raceForLandTransport.h"
#include "raceForAirTransport.h"
#include "raceForLandAndAirTransport.h"
#include"enumRace.h"
#include"enumMenu.h"
#include "enumOneMoreRaceOrExit.h"

// ���� ������ ���� �����
VehiclesDynamic::RaceType menuRaceTypeSelection();

// ��������� ���������
void setDisanceRace(VehiclesDynamic::Race& raceType);

// ����: ����������� �� ���� ������ �����
VehiclesDynamic::Menu regVehicleOrStartRace(VehiclesDynamic::Race& typeOfRace);

//����������� ��
void regVehicle(VehiclesDynamic::Race& typeOfRace);


//����� �����, ������� � ����� �����������
void startOfTheRace(VehiclesDynamic::Race& typeOfRace);

//����: ��� ���� ����� / ����� �� ���������
VehiclesDynamic::OneMoreRaceOrExit MenuPlayOrExit();

//������� ������ ������������������ �� ��������� ��
void deleteVehicle(VehiclesDynamic::Race& typeOfRace);

//���������� ��������� �����
void selectedRace(VehiclesDynamic::Race& typeOfRace);