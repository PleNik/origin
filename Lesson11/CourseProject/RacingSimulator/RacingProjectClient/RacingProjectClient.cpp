#include <iostream>
#include<string>
#include "functions.h"


int main() {

	setlocale(LC_ALL, "ru");

	
	
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	
	do { 
		switch (menuRaceTypeSelection()) //меню выбора типа гонки
		{
			case VehiclesDynamic::RaceType::RaceForLandTransport:
			{
			VehiclesDynamic::RaceForLandTransport raceForLandTransport; //создаем объект класса RaceForLandTransport
			
			selectedRace(raceForLandTransport); //реализация выбранной гонки
			}
		break;

		case VehiclesDynamic::RaceType::RaceForAirTransport:
			{
			VehiclesDynamic::RaceForAirTranspot raceForAirTransport; //создаем объект класса RaceForAirTranspot
			
			selectedRace(raceForAirTransport); //реализация выбранной гонки
			}	
			break;
			
		case VehiclesDynamic::RaceType::RaceForLandAndAirTransport:
			{
			VehiclesDynamic::RaceForLandAndAirTransport raceForLandAndAirTransport; //создаем объект класса RaceForLandAndAirTransport
			
			selectedRace(raceForLandAndAirTransport); //реализация выбранной гонки

			}
			break;
		}

	} while (MenuPlayOrExit() == VehiclesDynamic::OneMoreRaceOrExit::OneMoreRace); //до тех пор, пока не нажата клавиша Выхода
	
	
	

	return 0;
}