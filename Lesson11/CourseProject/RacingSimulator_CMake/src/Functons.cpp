#include "Functions.h"

//��������� ���������
void setDistance(RaceSimulatorLibraryDynamic::Race* raceType) {
    double userInputDistance;

    while (true) {

        std::cout << "\n������� ����� ��������� (������ ���� ������������): ";
        std::cin >> userInputDistance;
        if (userInputDistance < 0) {
            std::cout << "������! ��������� �� ����� ���� �������������!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else if (std::cin.fail()) {
            std::cout << "������! ������� �� �����!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else {
            raceType->SetDistance(userInputDistance);
            return;
        }

    }

}

//���� ����������� �� ���� ������ �����
RaceSimulatorLibraryDynamic::RegTransportOrStartRace regTransportOrStartRace(RaceSimulatorLibraryDynamic::Race* raceType) {
    int unsigned userInputRegTransportOrRunRace;

    while (true) {
        std::cout << "\n������ ���� ��������������� ���� �� 2 ������������ ��������";
        std::cout << "\n1. ���������������� ���������" << std::endl;
        if (raceType->GetArrTransports().size() >= 2) //���� ���������������� ������ 2-� ��, �� 2 ����� ������������
            std::cout << "2. ������ �����" << std::endl;
        std::cout << "�������� ��������: ";

        std::cin >> userInputRegTransportOrRunRace;
        RaceSimulatorLibraryDynamic::RegTransportOrStartRace regOrStartRace = static_cast<RaceSimulatorLibraryDynamic::RegTransportOrStartRace>(userInputRegTransportOrRunRace);

        if (regOrStartRace == RaceSimulatorLibraryDynamic::RegTransportOrStartRace::StartRace && raceType->GetArrTransports().size() < 2) {
            std::cout << "������! ���������������� ����� 2 ������������ �������" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else if (regOrStartRace < RaceSimulatorLibraryDynamic::RegTransportOrStartRace::RegTransport || regOrStartRace > RaceSimulatorLibraryDynamic::RegTransportOrStartRace::StartRace) {
            std::cout << "������! �������� ������������ ��������" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            return regOrStartRace;
    }
}

//����� ���� �����
RaceSimulatorLibraryDynamic::RaceType SelectRaceType() {
    while (true) {
        std::cout << "1. ����� ��� ��������� ����������" << std::endl;
        std::cout << "2. ����� ��� ���������� ����������" << std::endl;
        std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;

        std::cout << "�������� ��� �����: ";

        int unsigned userInputRaceType; //���������������� ���� ���� �����
        std::cin >> userInputRaceType;
        RaceSimulatorLibraryDynamic::RaceType race = static_cast<RaceSimulatorLibraryDynamic::RaceType>(userInputRaceType);

        if (race < RaceSimulatorLibraryDynamic::RaceType::LandRace || race > RaceSimulatorLibraryDynamic::RaceType::LandAndAirRace) {
            std::cout << "�������� ���� ���� �����!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            return race;
    }
}

//�������� ��������������� �� ����� ��������� ���������
bool TranspotIsAlreadyRegistered(RaceSimulatorLibraryDynamic::Race* raceType, std::string nameOfTransport) {
    bool transpotIsAlreadyRegistered = false;

    for (auto const& i : raceType->GetArrTransports()) {
        if (i->GetNameTransport() == nameOfTransport) {
            transpotIsAlreadyRegistered = true;
            break;
        }
    }
    return transpotIsAlreadyRegistered;

}


//����������� ���������� �� �����
void RegTransport(RaceSimulatorLibraryDynamic::Race* race) {
    bool registrationCompleted = false;

    unsigned userInputTypeTransportOrExitRegistration;

    while (!registrationCompleted) {
        std::cout << "\n" << race->GetNameRace() << ". ����������: " << race->GetDistance() << std::endl;

        if (race->GetArrTransports().size()) {
            std::cout << "������������������ ������������ ��������: ";
            for (int i = 0; i < race->GetArrTransports().size(); i++) {
                std::cout << race->GetArrTransports()[i]->GetNameTransport();
                if (i < race->GetArrTransports().size() - 1) std::cout << ", ";
            }
            std::cout << std::endl;
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


        std::cin >> userInputTypeTransportOrExitRegistration;
        RaceSimulatorLibraryDynamic::RegTransports regTransports = static_cast<RaceSimulatorLibraryDynamic::RegTransports>(userInputTypeTransportOrExitRegistration);

        if (regTransports < RaceSimulatorLibraryDynamic::RegTransports::_CompleteRegistration || regTransports > RaceSimulatorLibraryDynamic::RegTransports::_CarpetPlane)
            std::cout << "������! ��������� �������� �� ������������� �� ������ �� ��������" << std::endl;

        if (regTransports == RaceSimulatorLibraryDynamic::RegTransports::_CompleteRegistration && race->GetArrTransports().size() < 2)
            std::cout << "\n�� �� ������ �������� ������� �����������. ���������������� ����� 2 ������������ �������" << std::endl;

        else {
            switch (regTransports) {

            case RaceSimulatorLibraryDynamic::RegTransports::_CompleteRegistration:
                registrationCompleted = true;
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_AllTerrainBoots:
                if (TranspotIsAlreadyRegistered(race, "�������-���������"))
                    std::cout << "\n�������-��������� ��� ����������������!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* allTerrainBoots = new  RaceSimulatorLibraryDynamic::AllTerrainBoots;
                    if (race->AddTransport(allTerrainBoots)) {//���� ��������� �� �������� ����� race 
                        std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
                        delete allTerrainBoots;
                        allTerrainBoots = nullptr;
                    }
                    else
                        std::cout << "\n" << allTerrainBoots->GetNameTransport() << " ������� ���������������!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_Broom:
                if (TranspotIsAlreadyRegistered(race, "�����"))
                    std::cout << "\n����� ��� ����������������!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* broom = new RaceSimulatorLibraryDynamic::Broom;
                    if (race->AddTransport(broom)) {//���� ��������� �� �������� ����� race 
                        std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
                        delete broom;
                        broom = nullptr;
                    }
                    else
                        std::cout << "\n" << broom->GetNameTransport() << " ������� ���������������!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_Camel:
                if (TranspotIsAlreadyRegistered(race, "�������"))
                    std::cout << "\n������� ��� ���������������!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* camel = new RaceSimulatorLibraryDynamic::Camel;
                    if (race->AddTransport(camel)) {//���� ��������� �� �������� ����� race 
                        std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
                        delete camel;
                        camel = nullptr;
                    }
                    else
                        std::cout << "\n" << camel->GetNameTransport() << " ������� ���������������!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_Centaur:
                if (TranspotIsAlreadyRegistered(race, "�������"))
                    std::cout << "\n������� ��� ���������������!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* �entaur = new RaceSimulatorLibraryDynamic::Centaur;
                    if (race->AddTransport(�entaur)) {//���� ��������� �� �������� ����� race 
                        std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
                        delete �entaur;
                        �entaur = nullptr;
                    }
                    else
                        std::cout << "\n" << �entaur->GetNameTransport() << " ������� ���������������!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_Eagle:
                if (TranspotIsAlreadyRegistered(race, "����"))
                    std::cout << "\n���� ��� ���������������!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* eagle = new RaceSimulatorLibraryDynamic::Eagle;
                    if (race->AddTransport(eagle)) {//���� ��������� �� �������� ����� race 
                        std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
                        delete eagle;
                        eagle = nullptr;
                    }
                    else
                        std::cout << "\n" << eagle->GetNameTransport() << " ������� ���������������!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_CamelFast:
                if (TranspotIsAlreadyRegistered(race, "�������-���������"))
                    std::cout << "\n�������-��������� ��� ���������������!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* camelFast = new RaceSimulatorLibraryDynamic::CamelFast;
                    if (race->AddTransport(camelFast)) {//���� ��������� �� �������� ����� race 
                        std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
                        delete camelFast;
                        camelFast = nullptr;
                    }
                    else
                        std::cout << "\n" << camelFast->GetNameTransport() << " ������� ���������������!" << std::endl;

                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_CarpetPlane:
                if (TranspotIsAlreadyRegistered(race, "�����-�������"))
                    std::cout << "\n�����-������� ��� ���������������!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* carpetPlane = new RaceSimulatorLibraryDynamic::CarpetPlane;
                    if (race->AddTransport(carpetPlane)) {//���� ��������� �� �������� ����� race 
                        std::cout << "\n������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
                        delete carpetPlane;
                        carpetPlane = nullptr;
                    }
                    else
                        std::cout << "\n" << carpetPlane->GetNameTransport() << " ������� ���������������!" << std::endl;
                }


            }
        }

    }
}

//����� �����, ������� � ����� �����������
void startRace(RaceSimulatorLibraryDynamic::Race* raceType) {

    int size = raceType->GetArrTransports().size();
    std::vector<RaceSimulatorLibraryDynamic::ITransport*> resultArr = raceType->GetArrTransports();

    double distance = raceType->GetDistance();

    int j_size = size - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < j_size; j++) {
            if (resultArr[j]->RaceTime(distance) > resultArr[j + 1]->RaceTime(distance)) {
                std::vector<RaceSimulatorLibraryDynamic::ITransport*>v_temp = resultArr;
                v_temp[j] = resultArr[j + 1];
                resultArr[j + 1] = resultArr[j];
                resultArr[j] = v_temp[j];
                v_temp[j] = nullptr;
            }
        }
        j_size--;
    }

    //����� �����������
    std::cout << "\n���������� �����:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << resultArr[i]->GetNameTransport() << ". �����: " << resultArr[i]->RaceTime(distance) << std::endl;
    }

    //�������� ��������� ��������
    for (int i = 0; i < size; i++) {
        delete resultArr[i];
        resultArr[i] = nullptr;
    }
}

//����: ��� ���� �����/����� �� ���������
RaceSimulatorLibraryDynamic::OneMoreRaceOrExit MenuPlayOrExit() {
    unsigned userInput;

    while (true) {
        std::cout << "\n1. �������� ��� ���� �����" << std::endl;
        std::cout << "2. �����" << std::endl;
        std::cout << "�������� ��������: ";

        std::cin >> userInput;
        RaceSimulatorLibraryDynamic::OneMoreRaceOrExit oneMoreRaceOrExit = static_cast<RaceSimulatorLibraryDynamic::OneMoreRaceOrExit>(userInput);

        if (oneMoreRaceOrExit <  RaceSimulatorLibraryDynamic::OneMoreRaceOrExit::OneMoreRace || oneMoreRaceOrExit > RaceSimulatorLibraryDynamic::OneMoreRaceOrExit::Exit) {
            std::cout << "������! ������� ������������ ��������" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            return oneMoreRaceOrExit;
    }
}

//������� ������ ������������������ ��
void deleteTransports(RaceSimulatorLibraryDynamic::Race* raceType) {
    int size = raceType->GetArrTransports().size();
    for (int i = 0; i < size; i++) {
        raceType->GetArrTransports()[i] = nullptr;
    }
}

//���������� ��������� �����
void RaceSelected(RaceSimulatorLibraryDynamic::Race* raceType) {
    setDistance(raceType); //��������� ���������

    while (regTransportOrStartRace(raceType) == RaceSimulatorLibraryDynamic::RegTransportOrStartRace::RegTransport) {
        RegTransport(raceType);
    }
    startRace(raceType);
    deleteTransports(raceType);
}