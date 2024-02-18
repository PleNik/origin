#pragma once

#include "enumRace.h"
#include "enumMenu.h"
#include "enumVehicle.h"
#include "enumOneMoreRaceOrExit.h" 
#include "invalidTypeException.h"
#include "invalidRaceDistanceException.h"

//проверка на исключение: неверно введенное значение типов гонок
void checkUserInputRace(VehiclesDynamic::RaceType& userInput);

//проверка на исключение: неверно введенное значение дистанции
void checkUserInputDistance(double distance);

//проверка на исключение: неверно введенное значение пунктов меню
void checkUserInputMenu(VehiclesDynamic::Menu& userInput);

//проеверка на исключение: неверно введенное значение выбора ТС
void checkUserInputVehicleType(VehiclesDynamic::VehicleType& userInput);

//проверка на исключение: неверно введенное значение выбора пунктов: еще одна гонка/выход
void checkUserInputOneMoreRaceOrExit(VehiclesDynamic::OneMoreRaceOrExit& userInput);