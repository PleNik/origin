#include "exceptions.h"

//�������� �� ����������: ������� ��������� �������� ����� �����
void checkUserInputRace(VehiclesDynamic::RaceType& userInput) {

	if (userInput < VehiclesDynamic::RaceType::RaceForLandTransport || userInput > VehiclesDynamic::RaceType::RaceForLandAndAirTransport)
		throw VehiclesDynamic::InvalidTypeException("��������� �������� �� ������������� �� ������ �� ��������");
}

//�������� �� ����������: ������� ��������� �������� ���������
void checkUserInputDistance(double distance) {

	if (distance < 0)
		throw VehiclesDynamic::InvalidRaceDistanceException("������� ������������� ��������");

	if (std::cin.fail())
		throw VehiclesDynamic::InvalidRaceDistanceException("������� �� �������� ��������");

}

//�������� �� ����������: ������� ��������� �������� ������� ����
void checkUserInputMenu(VehiclesDynamic::Menu& userInput) {

	if (userInput == VehiclesDynamic::Menu::StartTheRace && VehiclesDynamic::Vehicle::counterOfVehicle < 2)
		throw VehiclesDynamic::InvalidTypeException("����� �� ����� ���� ������, ���������������� ����� 2 ������������ �������");

	else if (userInput < VehiclesDynamic::Menu::RegisterVehicle || userInput > VehiclesDynamic::Menu::StartTheRace)
		throw VehiclesDynamic::InvalidTypeException("��������� �������� �� ������������� �� ������ �� ��������");
}

//��������� �� ����������: ������� ��������� �������� ������ ��
void checkUserInputVehicleType(VehiclesDynamic::VehicleType& userInput) {

	if (userInput < VehiclesDynamic::VehicleType::_CompleteRegistration || userInput > VehiclesDynamic::VehicleType::_MagicCarpet)
		throw VehiclesDynamic::InvalidTypeException("��������� �������� �� ������������� �� ������ �� ��������");
}

//�������� �� ����������: ������� ��������� �������� ������ �������: ��� ���� �����/�����
void checkUserInputOneMoreRaceOrExit(VehiclesDynamic::OneMoreRaceOrExit& userInput) {

	if (userInput < VehiclesDynamic::OneMoreRaceOrExit::OneMoreRace || userInput > VehiclesDynamic::OneMoreRaceOrExit::Exit)
		throw VehiclesDynamic::InvalidTypeException("��������� �������� �� ������������� �� ������ �� ��������");

}