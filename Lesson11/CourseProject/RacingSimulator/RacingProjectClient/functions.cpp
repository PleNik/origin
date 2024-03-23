#include "functions.h"

//меню выбора типа гонки
VehiclesDynamic::RaceType menuRaceTypeSelection() {
	while (true) {

		std::cout << "1. Гонка для наземного транспорта" << std::endl;
		std::cout << "2. Гонка для воздушного транспорта" << std::endl;
		std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

		std::cout << "Выбирите тип гонки: ";

		int unsigned userInputRace;

		std::cin >> userInputRace;
		VehiclesDynamic::RaceType race = static_cast<VehiclesDynamic::RaceType>(userInputRace);

		if (race < VehiclesDynamic::RaceType::RaceForLandTransport || race > VehiclesDynamic::RaceType::RaceForLandAndAirTransport) {
			std::cout << "Ошибка ввода типа гонки: введенное значение не соответствует ни одному из заданных" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
			return race;
	}
}

//установка дистанции
void setDisanceRace(VehiclesDynamic::Race& raceType) {

	double userInputDistance;

	while (true) {

		std::cout << "\nУкажите длину дистанции (должна быть положительна): ";
		std::cin >> userInputDistance;

		if (userInputDistance < 0) {
			std::cout << "Ошибка ввода дистанции: введено отрицательное значение" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (std::cin.fail()) {
			std::cout << "Ошибка ввода дистанции: введено не числовое значение" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else {
			raceType.SetDistance(userInputDistance);
			std::cout << "\nДолжно быть зарегистировано хотя бы 2 транспортных средства" << std::endl;
			break;
		}
		
	}
}

//меню: регистрация ТС либо начала гонки
VehiclesDynamic::Menu regVehicleOrStartRace(VehiclesDynamic::Race& typeOfRace) {

	int  userInput;
	while (true) {
		std::cout << "\n1. Зарегистрировать транспорт" << std::endl;
		if (typeOfRace.vehicles.size() >= 2) //если зарегистрировано меньше 2-х ТС, то 2 пункт игнонировать
			std::cout << "2. Начать гонку" << std::endl;
		std::cout << "Выберите действие: ";

		std::cin >> userInput;
		VehiclesDynamic::Menu regVehicleOrStartRace = static_cast<VehiclesDynamic::Menu>(userInput);

		if (regVehicleOrStartRace == VehiclesDynamic::Menu::StartTheRace && typeOfRace.vehicles.size() < 2) {
			std::cout << "Ошибка ввода: гонка не может быть начата, зарегистрировано менее 2 транспортных средств" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (regVehicleOrStartRace < VehiclesDynamic::Menu::RegisterVehicle || regVehicleOrStartRace > VehiclesDynamic::Menu::StartTheRace) {
			std::cout << "Ошибка ввода : введенное значение не соответствует ни одному из заданных" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
			return regVehicleOrStartRace;
	}
}


//регистрация ТС
void regVehicle(VehiclesDynamic::Race& typeOfRace) {

	bool registrationCompleted = false;

	int  userInput;
	while (!registrationCompleted) {
		std::cout << "\n" << typeOfRace.GetName() << ". Расстояние: " << typeOfRace.GetDistance() << std::endl;

		if (typeOfRace.vehicles.size()) {

			std::cout << "Зарегистрированные транспортные средства: ";
			for (int i = 0; i < typeOfRace.vehicles.size(); i++) {
				std::cout << typeOfRace.vehicles[i]->getNameOfVehicle();
				if (i < typeOfRace.vehicles.size() - 1) std::cout << ", ";
			}
			std::cout << "\n";
		}

		std::cout << "1. Ботинки-вездеходы" << std::endl;
		std::cout << "2. Метла" << std::endl;
		std::cout << "3. Верблюд" << std::endl;
		std::cout << "4. Кенатавр" << std::endl;
		std::cout << "5. Орел" << std::endl;
		std::cout << "6. Верблюд-бысроход" << std::endl;
		std::cout << "7. Ковер-самолет" << std::endl;
		std::cout << "0. Закончить регистрацию" << std::endl;
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

		std::cin >> userInput;
		VehiclesDynamic::VehicleType regVehicle = static_cast<VehiclesDynamic::VehicleType>(userInput);

		if (regVehicle < VehiclesDynamic::VehicleType::_CompleteRegistration || regVehicle > VehiclesDynamic::VehicleType::_MagicCarpet) {
			std::cout << "Ошибка ввода: введенное значение не соответствует ни одному из заданных" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}

		if (regVehicle == VehiclesDynamic::VehicleType::_CompleteRegistration && typeOfRace.vehicles.size() < 2)
			std::cout << "\nВы не можете прервать процесс регистрации. Зарегистрировано менее 2 транспортных средств" << std::endl;
		else
			switch (regVehicle) {

			case VehiclesDynamic::_CompleteRegistration:

				registrationCompleted = true;
				break;

			case VehiclesDynamic::_AllTerrainBoots:
			{
				if (VehiclesDynamic::AllTerrainBoots::counterOfAllTerrainBoots) {
					std::cout << "\nБотинки-везедходы уже зарегистрирован!" << std::endl;
				}
				else {

					VehiclesDynamic::AllTerrainBoots allTerrainBoots; //создал объект класса AllTerrainBoots
					
					if (typeOfRace.AddVehicle(&allTerrainBoots)) {
						std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					}
					else std::cout << "\n" << allTerrainBoots.getNameOfVehicle() << " успешно зарегистрирован!" << std::endl;
				}
			}
			break;

			case VehiclesDynamic::_Broom:
			{
				if (VehiclesDynamic::Broom::counterOfBroom) {
					std::cout << "\nМетла уже зарегистрирован!" << std::endl;
				}
				else {

					VehiclesDynamic::Broom broom;
					if (typeOfRace.AddVehicle(&broom)) {
						std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					}
					else std::cout << "\n" << broom.getNameOfVehicle() << " успешно зарегистрирован!" << std::endl;

				}
			}
			break;

			case VehiclesDynamic::_Camel:
			{
				if (VehiclesDynamic::Camel::counterOfCamel) {
					std::cout << "\nВерблюд уже зарегистрирован!" << std::endl;
				}
				else {

					VehiclesDynamic::Camel camel;
					if (typeOfRace.AddVehicle(&camel)) {
						std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					}
					else std::cout << "\n" << camel.getNameOfVehicle() << " успешно зарегистрирован!" << std::endl;
				}

			}
			break;

			case VehiclesDynamic::_Centaur:
			{
				if (VehiclesDynamic::Centaur::counterOfCentaur) {
					std::cout << "\nКентавр уже зарегистрирован!" << std::endl;
				}
				else {

					VehiclesDynamic::Centaur centaur;
					if (typeOfRace.AddVehicle(&centaur)) {
						std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					}
					else std::cout << "\n" << centaur.getNameOfVehicle() << " успешно зарегистрирован!" << std::endl;
				}
			}
			break;

			case VehiclesDynamic::_Eagle:
			{
				if (VehiclesDynamic::Eagle::counterOfEagle) {
					std::cout << "\nОрел уже зарегистрирован!" << std::endl;
				}
				else {

					VehiclesDynamic::Eagle eagle;
					if (typeOfRace.AddVehicle(&eagle)) {
						std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					}
					else std::cout << "\n" << eagle.getNameOfVehicle() << " успешно зарегистрирован!" << std::endl;
				}
			}
			break;

			case VehiclesDynamic::_CamelWalker:
			{
				if (VehiclesDynamic::CamelWalker::counterOfCamelWalker) {
					std::cout << "\nВерблюд-быстроход уже зарегистрирован!" << std::endl;
				}
				else {

					VehiclesDynamic::CamelWalker camelWalker;
					if (typeOfRace.AddVehicle(&camelWalker)) {
						std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					}
					else std::cout << "\n" << camelWalker.getNameOfVehicle() << " успешно зарегистрирован!" << std::endl;
				}
			}
			break;

			case VehiclesDynamic::_MagicCarpet:
			{
				if (VehiclesDynamic::MagicCarpet::counterOfMagicCarpet) {
					std::cout << "\nКовер-самолет уже зарегистрирован!" << std::endl;
				}
				else {

					VehiclesDynamic::MagicCarpet magicCarpet;
					if (typeOfRace.AddVehicle(&magicCarpet)) {
						std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					}
					else std::cout << "\n" << magicCarpet.getNameOfVehicle() << " успешно зарегистрирован!" << std::endl;
				}
			}
			break;

			}
	}
}

//старт гонки, подсчет и вывод результатов
void startOfTheRace(VehiclesDynamic::Race& typeOfRace) {

	int j = 0;
	int size = typeOfRace.vehicles.size();

	do {

		for (int i = typeOfRace.vehicles.size() - 1; i > j; i--) {


			if (typeOfRace.CalcTimeRide(typeOfRace.vehicles[i]) < typeOfRace.CalcTimeRide(typeOfRace.vehicles[i-1])) {
				std::vector<VehiclesDynamic::Vehicle*> temp;
				temp.resize(size);

				temp[i] = typeOfRace.vehicles[i];
				typeOfRace.vehicles[i] = typeOfRace.vehicles[i - 1];
				typeOfRace.vehicles[i - 1] = temp[i];

			}
		}

		j++;

	} while (j < typeOfRace.vehicles.size());

	//вывод результатов
	std::cout << "\nРезультаты гонки:" << std::endl;

	for (int i = 0; i < size; i++) {

		std::cout << i + 1 << ". " << typeOfRace.vehicles[i]->getNameOfVehicle() << ". Время: "
			<< typeOfRace.CalcTimeRide(typeOfRace.vehicles[i]) << std::endl;
	}
}

//меню: еще одна гонка/выход из программы
VehiclesDynamic::OneMoreRaceOrExit MenuPlayOrExit() {

	int  userInput;
	while (true) {
		std::cout << "\n1. Провести еще одну гонку" << std::endl;
		std::cout << "2. Выйти" << std::endl;
		std::cout << "Выберите действие: ";

		std::cin >> userInput;
		VehiclesDynamic::OneMoreRaceOrExit oneMoreRaceOrExit = static_cast<VehiclesDynamic::OneMoreRaceOrExit>(userInput);
		if (oneMoreRaceOrExit < VehiclesDynamic::OneMoreRaceOrExit::OneMoreRace || oneMoreRaceOrExit > VehiclesDynamic::OneMoreRaceOrExit::Exit) {

			std::cout << "Ошибка ввода: введенное значение не соответствует ни одному из заданных" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else {
			std::cout << "\n";
			return oneMoreRaceOrExit;
		}
	}
}

//очистка списка зарегистрированных ТС счетчиков ТС
void deleteVehicle(VehiclesDynamic::Race& typeOfRace) {

	VehiclesDynamic::AllTerrainBoots::counterOfAllTerrainBoots = 0;
	VehiclesDynamic::Broom::counterOfBroom = 0;
	VehiclesDynamic::Camel::counterOfCamel = 0;
	VehiclesDynamic::Centaur::counterOfCentaur = 0;
	VehiclesDynamic::Eagle::counterOfEagle = 0;
	VehiclesDynamic::CamelWalker::counterOfCamelWalker = 0;
	VehiclesDynamic::MagicCarpet::counterOfMagicCarpet = 0;
	typeOfRace.vehicles.clear();
}

//реализация выбранной гонки
void selectedRace(VehiclesDynamic::Race& typeOfRace) {
	setDisanceRace(typeOfRace); //установка дистанции

	while (regVehicleOrStartRace(typeOfRace) == VehiclesDynamic::Menu::RegisterVehicle) {

		regVehicle(typeOfRace); //регистрация ТС
	}
	startOfTheRace(typeOfRace); //старт гонки

	deleteVehicle(typeOfRace); //очистка списка зарегистрированных ТС и счетчиков ТС
}
