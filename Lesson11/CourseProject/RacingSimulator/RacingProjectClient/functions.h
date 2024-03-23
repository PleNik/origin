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

// меню выбора типа гонки
VehiclesDynamic::RaceType menuRaceTypeSelection();

// установка дистанции
void setDisanceRace(VehiclesDynamic::Race& raceType);

// меню: регистрации ТС либо начала гонки
VehiclesDynamic::Menu regVehicleOrStartRace(VehiclesDynamic::Race& typeOfRace);

//регистрация ТС
void regVehicle(VehiclesDynamic::Race& typeOfRace);


//старт гонки, подсчет и вывод результатов
void startOfTheRace(VehiclesDynamic::Race& typeOfRace);

//меню: еще одна гонка / выход из программы
VehiclesDynamic::OneMoreRaceOrExit MenuPlayOrExit();

//очистка списка зарегистрированных ТС счетчиков ТС
void deleteVehicle(VehiclesDynamic::Race& typeOfRace);

//реализация выбранной гонки
void selectedRace(VehiclesDynamic::Race& typeOfRace);