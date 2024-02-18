#include "functions.h"

//���� ������ ���� �����
VehiclesDynamic::RaceType menuRaceTypeSelection() {
	while (true) {

		std::cout << "1. ����� ��� ��������� ����������" << std::endl;
		std::cout << "2. ����� ��� ���������� ����������" << std::endl;
		std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;

		std::cout << "�������� ��� �����: ";

		int unsigned userInputRace;

		try {

			std::cin >> userInputRace;
			VehiclesDynamic::RaceType race = static_cast<VehiclesDynamic::RaceType>(userInputRace);
			checkUserInputRace(race);

			return race;
		}
		catch (const VehiclesDynamic::InvalidTypeException& ex) {

			std::cout << "������ ����� ���� �����: " << ex.what() << std::endl;
			std::cout << std::endl;

			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}

}

//��������� ���������
void setDisanceRace() {

	double userInputDistance;

	while (true) {

		std::cout << "\n������� ����� ��������� (������ ���� ������������): ";

		try {

			std::cin >> userInputDistance;
			checkUserInputDistance(userInputDistance);
			VehiclesDynamic::Vehicle::distance = userInputDistance; //��������, ����� �� ���?
			VehiclesDynamic::Race::distance = userInputDistance;
			std::cout << "\n������ ���� ��������������� ���� �� 2 ������������ ��������" << std::endl;
			break;
		}
		catch (const VehiclesDynamic::InvalidRaceDistanceException& ex) {
			std::cout << "������ ����� ��������� " << ex.what() << std::endl;
			std::cout << std::endl;

			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}

	}
}

//����: ����������� �� ���� ������ �����
VehiclesDynamic::Menu regVehicleOrStartRace() {

	int  userInput;
	while (true) {
		std::cout << "\n1. ���������������� ���������" << std::endl;
		if (VehiclesDynamic::Vehicle::counterOfVehicle >= 2) //���� ���������������� ������ 2-� ��, �� 2 ����� ������������
			std::cout << "2. ������ �����" << std::endl;
		std::cout << "�������� ��������: ";

		try {
			std::cin >> userInput;
			VehiclesDynamic::Menu regVehicleOrStartRace = static_cast<VehiclesDynamic::Menu>(userInput);
			checkUserInputMenu(regVehicleOrStartRace);
			return regVehicleOrStartRace;
		}
		catch (const VehiclesDynamic::InvalidTypeException& ex) {
			std::cout << "������ �����: " << ex.what() << std::endl;
			std::cout << std::endl;

			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}

}

//����������� ��
void regVehicle(VehiclesDynamic::Race& typeOfRace) {

	bool registrationCompleted = false;

	int  userInput;
	while (!registrationCompleted) {
		std::cout << "\n" << typeOfRace.GetName() << ". ����������: " << typeOfRace.distance << std::endl;

		if (VehiclesDynamic::Vehicle::counterOfVehicle) {

			std::cout << "������������������ ������������ ��������: ";
			for (int i = 0; i < typeOfRace.vehicles.size(); i++) {
				std::cout << typeOfRace.vehicles[i].getNameOfVehicle();
				if (i < typeOfRace.vehicles.size() - 1) std::cout << ", ";
			}
			std::cout << "\n";
		}

		std::cout << "1. �������-���������" << std::endl;
		std::cout << "2. �����" << std::endl;
		std::cout << "3. �������" << std::endl;
		std::cout << "4. ��������" << std::endl;
		std::cout << "5. ����" << std::endl;
		std::cout << "6. �������-��������" << std::endl;
		std::cout << "7. �����-�������" << std::endl;
		std::cout << "0. ��������� �����������" << std::endl;
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";

		try {

			std::cin >> userInput;
			VehiclesDynamic::VehicleType regVehicle = static_cast<VehiclesDynamic::VehicleType>(userInput);
			checkUserInputVehicleType(regVehicle);

			if (regVehicle == VehiclesDynamic::VehicleType::_CompleteRegistration && VehiclesDynamic::Vehicle::counterOfVehicle < 2)
				std::cout << "\n�� �� ������ �������� ������� �����������. ���������������� ����� 2 ������������ �������" << std::endl;
			else
				switch (regVehicle) {

				case VehiclesDynamic::_CompleteRegistration:

					registrationCompleted = true;
					break;

				case VehiclesDynamic::_AllTerrainBoots:
				{
					if (VehiclesDynamic::AllTerrainBoots::counterOfAllTerrainBoots) {
						std::cout << "\n�������-��������� ��� ���������������!" << std::endl;
					}
					else {

						VehiclesDynamic::AllTerrainBoots allTerrainBoots; //������ ������ ������ AllTerrainBoots
						if (typeOfRace.AddVehicle(allTerrainBoots)) {
							std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
						}
						else std::cout << "\n" << allTerrainBoots.getNameOfVehicle() << " ������� ���������������!" << std::endl;
					}
				}
				break;

				case VehiclesDynamic::_Broom:
				{
					if (VehiclesDynamic::Broom::counterOfBroom) {
						std::cout << "\n����� ��� ���������������!" << std::endl;
					}
					else {

						VehiclesDynamic::Broom broom;
						if (typeOfRace.AddVehicle(broom)) {
							std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
						}
						else std::cout << "\n" << broom.getNameOfVehicle() << " ������� ���������������!" << std::endl;

					}
				}
				break;

				case VehiclesDynamic::_Camel:
				{
					if (VehiclesDynamic::Camel::counterOfCamel) {
						std::cout << "\n������� ��� ���������������!" << std::endl;
					}
					else {

						VehiclesDynamic::Camel camel;
						if (typeOfRace.AddVehicle(camel)) {
							std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
						}
						else std::cout << "\n" << camel.getNameOfVehicle() << " ������� ���������������!" << std::endl;
					}

				}
				break;

				case VehiclesDynamic::_Centaur:
				{
					if (VehiclesDynamic::Centaur::counterOfCentaur) {
						std::cout << "\n������� ��� ���������������!" << std::endl;
					}
					else {

						VehiclesDynamic::Centaur centaur;
						if (typeOfRace.AddVehicle(centaur)) {
							std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
						}
						else std::cout << "\n" << centaur.getNameOfVehicle() << " ������� ���������������!" << std::endl;
					}
				}
				break;

				case VehiclesDynamic::_Eagle:
				{
					if (VehiclesDynamic::Eagle::counterOfEagle) {
						std::cout << "\n���� ��� ���������������!" << std::endl;
					}
					else {

						VehiclesDynamic::Eagle eagle;
						if (typeOfRace.AddVehicle(eagle)) {
							std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
						}
						else std::cout << "\n" << eagle.getNameOfVehicle() << " ������� ���������������!" << std::endl;
					}
				}
				break;

				case VehiclesDynamic::_CamelWalker:
				{
					if (VehiclesDynamic::CamelWalker::counterOfCamelWalker) {
						std::cout << "\n�������-��������� ��� ���������������!" << std::endl;
					}
					else {

						VehiclesDynamic::CamelWalker camelWalker;
						if (typeOfRace.AddVehicle(camelWalker)) {
							std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
						}
						else std::cout << "\n" << camelWalker.getNameOfVehicle() << " ������� ���������������!" << std::endl;
					}
				}
				break;

				case VehiclesDynamic::_MagicCarpet:
				{
					if (VehiclesDynamic::MagicCarpet::counterOfMagicCarpet) {
						std::cout << "\n�����-������� ��� ���������������!" << std::endl;
					}
					else {

						VehiclesDynamic::MagicCarpet magicCarpet;
						if (typeOfRace.AddVehicle(magicCarpet)) {
							std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
						}
						else std::cout << "\n" << magicCarpet.getNameOfVehicle() << " ������� ���������������!" << std::endl;
					}
				}
				break;

				}

		}
		catch (const VehiclesDynamic::InvalidTypeException& ex) {
			std::cout << "������ �����: " << ex.what() << std::endl;
			std::cout << std::endl;

			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}

//����� �����, ������� � ����� �����������
void startOfTheRace(VehiclesDynamic::Race& typeOfRace) {

	int j = 0;
	int size = typeOfRace.vehicles.size();

	do {

		for (int i = typeOfRace.vehicles.size() - 1; i > j; i--) {


			if (typeOfRace.vehicles[i].getTimeOfRace() < typeOfRace.vehicles[i - 1].getTimeOfRace()) {
				std::vector<VehiclesDynamic::Vehicle> temp;
				temp.resize(size);

				temp[i] = typeOfRace.vehicles[i];
				typeOfRace.vehicles[i] = typeOfRace.vehicles[i - 1];
				typeOfRace.vehicles[i - 1] = temp[i];

			}
		}

		j++;

	} while (j < typeOfRace.vehicles.size());

	//����� �����������
	std::cout << "\n���������� �����:" << std::endl;

	for (int i = 0; i < size; i++) {

		std::cout << i + 1 << ". " << typeOfRace.vehicles[i].getNameOfVehicle() << ". " << typeOfRace.vehicles[i].getTimeOfRace() << std::endl;
	}
}

//����: ��� ���� �����/����� �� ���������
VehiclesDynamic::OneMoreRaceOrExit MenuPlayOrExit() {

	int  userInput;
	while (true) {
		std::cout << "\n1. �������� ��� ���� �����" << std::endl;
		std::cout << "2. �����" << std::endl;
		std::cout << "�������� ��������: ";

		try {
			std::cin >> userInput;
			VehiclesDynamic::OneMoreRaceOrExit oneMoreRaceOrExit = static_cast<VehiclesDynamic::OneMoreRaceOrExit>(userInput);
			checkUserInputOneMoreRaceOrExit(oneMoreRaceOrExit);
			std::cout << "\n";
			return oneMoreRaceOrExit;
		}
		catch (const VehiclesDynamic::InvalidTypeException& ex) {
			std::cout << "������ �����: " << ex.what() << std::endl;
			std::cout << std::endl;

			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}

//������� ������ ������������������ �� ��������� ��
void deleteVehicle(VehiclesDynamic::Race& typeOfRace) {

	VehiclesDynamic::AllTerrainBoots::counterOfAllTerrainBoots = 0;
	VehiclesDynamic::Broom::counterOfBroom = 0;
	VehiclesDynamic::Camel::counterOfCamel = 0;
	VehiclesDynamic::Centaur::counterOfCentaur = 0;
	VehiclesDynamic::Eagle::counterOfEagle = 0;
	VehiclesDynamic::CamelWalker::counterOfCamelWalker = 0;
	VehiclesDynamic::MagicCarpet::counterOfMagicCarpet = 0;
	VehiclesDynamic::Vehicle::counterOfVehicle = 0;

	typeOfRace.vehicles.clear();
}

//���������� ��������� �����
void selectedRace(VehiclesDynamic::Race& typeOfRace) {
	setDisanceRace(); //��������� ���������

	while (regVehicleOrStartRace() == VehiclesDynamic::Menu::RegisterVehicle) {

		regVehicle(typeOfRace); //����������� ��
	}
	startOfTheRace(typeOfRace); //����� �����

	deleteVehicle(typeOfRace); //������� ������ ������������������ �� � ��������� ��
}
