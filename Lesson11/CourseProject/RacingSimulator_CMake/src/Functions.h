pragma once

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

//установка дистанции
void setDistance(RaceSimulatorLibraryDynamic::Race* raceType);

//меню регистраци¤ “— либо начало гонки
RaceSimulatorLibraryDynamic::RegTransportOrStartRace regTransportOrStartRace(RaceSimulatorLibraryDynamic::Race* raceType);

//выбор типа гонки
RaceSimulatorLibraryDynamic::RaceType SelectRaceType();

//проверка зарегистрирован ли ранее выбранный транспорт
bool TranspotIsAlreadyRegistered(RaceSimulatorLibraryDynamic::Race* raceType, std::string nameOfTransport);


//регистраци¤ транспорта на гонку
void RegTransport(RaceSimulatorLibraryDynamic::Race* race);

//старт гонки, подсчет и вывод результатов
void startRace(RaceSimulatorLibraryDynamic::Race* raceType);

//меню: еще одна гонка/выход из программы
RaceSimulatorLibraryDynamic::OneMoreRaceOrExit MenuPlayOrExit();

//очистка списка зарегистрированных “—
void deleteTransports(RaceSimulatorLibraryDynamic::Race* raceType);

//реализаци¤ выбранной гонки
void RaceSelected(RaceSimulatorLibraryDynamic::Race* raceType);
