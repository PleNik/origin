#include "exceptions.h"

//проверка на исключение: неверно введенное значение типов гонок
void checkUserInputRace(VehiclesDynamic::RaceType& userInput) {

	if (userInput < VehiclesDynamic::RaceType::RaceForLandTransport || userInput > VehiclesDynamic::RaceType::RaceForLandAndAirTransport)
		throw VehiclesDynamic::InvalidTypeException("введенное значение не соответствует ни одному из заданных");
}

//проверка на исключение: неверно введенное значение дистанции
void checkUserInputDistance(double distance) {

	if (distance < 0)
		throw VehiclesDynamic::InvalidRaceDistanceException("введено отрицательное значение");

	if (std::cin.fail())
		throw VehiclesDynamic::InvalidRaceDistanceException("введено не числовое значение");

}

//проверка на исключение: неверно введенное значение пунктов меню
void checkUserInputMenu(VehiclesDynamic::Menu& userInput) {

	if (userInput == VehiclesDynamic::Menu::StartTheRace && VehiclesDynamic::Vehicle::counterOfVehicle < 2)
		throw VehiclesDynamic::InvalidTypeException("гонка не может быть начата, зарегистрировано менее 2 транспортных средств");

	else if (userInput < VehiclesDynamic::Menu::RegisterVehicle || userInput > VehiclesDynamic::Menu::StartTheRace)
		throw VehiclesDynamic::InvalidTypeException("введенное значение не соответствует ни одному из заданных");
}

//проеверка на исключение: неверно введенное значение выбора ТС
void checkUserInputVehicleType(VehiclesDynamic::VehicleType& userInput) {

	if (userInput < VehiclesDynamic::VehicleType::_CompleteRegistration || userInput > VehiclesDynamic::VehicleType::_MagicCarpet)
		throw VehiclesDynamic::InvalidTypeException("введенное значение не соответствует ни одному из заданных");
}

//проверка на исключение: неверно введенное значение выбора пунктов: еще одна гонка/выход
void checkUserInputOneMoreRaceOrExit(VehiclesDynamic::OneMoreRaceOrExit& userInput) {

	if (userInput < VehiclesDynamic::OneMoreRaceOrExit::OneMoreRace || userInput > VehiclesDynamic::OneMoreRaceOrExit::Exit)
		throw VehiclesDynamic::InvalidTypeException("введенное значение не соответствует ни одному из заданных");

}