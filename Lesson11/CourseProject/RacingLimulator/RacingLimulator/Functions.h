#pragma once

#include "CamelFast.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "AirTransport.h"
#include "CarpetPlane.h"
#include "Eagle.h"
#include "Broom.h"
#include "LandRace.h"
#include "AirRace.h"
#include "LandAndAirRace.h"

//��������� ���������
void setDistance(RaceSimulatorLibraryDynamic::Race* raceType);

//���� ����������� �� ���� ������ �����
RaceSimulatorLibraryDynamic::RegTransportOrStartRace regTransportOrStartRace(RaceSimulatorLibraryDynamic::Race* raceType);

//����� ���� �����
RaceSimulatorLibraryDynamic::RaceType SelectRaceType();

//�������� ��������������� �� ����� ��������� ���������
bool TranspotIsAlreadyRegistered(RaceSimulatorLibraryDynamic::Race* raceType, std::string nameOfTransport);


//����������� ���������� �� �����
void RegTransport(RaceSimulatorLibraryDynamic::Race* race);

//����� �����, ������� � ����� �����������
void startRace(RaceSimulatorLibraryDynamic::Race* raceType);

//����: ��� ���� �����/����� �� ���������
RaceSimulatorLibraryDynamic::OneMoreRaceOrExit MenuPlayOrExit();

//������� ������ ������������������ ��
void deleteTransports(RaceSimulatorLibraryDynamic::Race* raceType);

//���������� ��������� �����
void RaceSelected(RaceSimulatorLibraryDynamic::Race* raceType);