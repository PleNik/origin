#include "Functions.h"

//установка дистанции
void setDistance(RaceSimulatorLibraryDynamic::Race* raceType) {
    double userInputDistance;

    while (true) {

        std::cout << "\nУкажите длину дистанции (должна быть положительна): ";
        std::cin >> userInputDistance;
        if (userInputDistance < 0) {
            std::cout << "Ошибка! Дистанция не может быть отрицательной!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else if (std::cin.fail()) {
            std::cout << "Ошибка! Введено не число!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else {
            raceType->SetDistance(userInputDistance);
            return;
        }

    }

}

//меню регистрация ТС либо начало гонки
RaceSimulatorLibraryDynamic::RegTransportOrStartRace regTransportOrStartRace(RaceSimulatorLibraryDynamic::Race* raceType) {
    int unsigned userInputRegTransportOrRunRace;

    while (true) {
        std::cout << "\nДолжно быть зарегистировано хотя бы 2 транспортных средства";
        std::cout << "\n1. Зарегистрировать транспорт" << std::endl;
        if (raceType->GetArrTransports().size() >= 2) //если зарегистрировано меньше 2-х ТС, то 2 пункт игнонировать
            std::cout << "2. Начать гонку" << std::endl;
        std::cout << "Выберите действие: ";

        std::cin >> userInputRegTransportOrRunRace;
        RaceSimulatorLibraryDynamic::RegTransportOrStartRace regOrStartRace = static_cast<RaceSimulatorLibraryDynamic::RegTransportOrStartRace>(userInputRegTransportOrRunRace);

        if (regOrStartRace == RaceSimulatorLibraryDynamic::RegTransportOrStartRace::StartRace && raceType->GetArrTransports().size() < 2) {
            std::cout << "Ошибка! Зарегистрировано менее 2 транспортных средств" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else if (regOrStartRace < RaceSimulatorLibraryDynamic::RegTransportOrStartRace::RegTransport || regOrStartRace > RaceSimulatorLibraryDynamic::RegTransportOrStartRace::StartRace) {
            std::cout << "Ошибка! Ввведено некорректное значение" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            return regOrStartRace;
    }
}

//выбор типа гонки
RaceSimulatorLibraryDynamic::RaceType SelectRaceType() {
    while (true) {
        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

        std::cout << "Выберите тип гонки: ";

        int unsigned userInputRaceType; //пользовательский ввод типа гонки
        std::cin >> userInputRaceType;
        RaceSimulatorLibraryDynamic::RaceType race = static_cast<RaceSimulatorLibraryDynamic::RaceType>(userInputRaceType);

        if (race < RaceSimulatorLibraryDynamic::RaceType::LandRace || race > RaceSimulatorLibraryDynamic::RaceType::LandAndAirRace) {
            std::cout << "Неверный ввод типа гонки!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            return race;
    }
}

//проверка зарегистрирован ли ранее выбранный транспорт
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


//регистрация транспорта на гонку
void RegTransport(RaceSimulatorLibraryDynamic::Race* race) {
    bool registrationCompleted = false;

    unsigned userInputTypeTransportOrExitRegistration;

    while (!registrationCompleted) {
        std::cout << "\n" << race->GetNameRace() << ". Расстояние: " << race->GetDistance() << std::endl;

        if (race->GetArrTransports().size()) {
            std::cout << "Зарегистрированные транспортные средства: ";
            for (int i = 0; i < race->GetArrTransports().size(); i++) {
                std::cout << race->GetArrTransports()[i]->GetNameTransport();
                if (i < race->GetArrTransports().size() - 1) std::cout << ", ";
            }
            std::cout << std::endl;
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


        std::cin >> userInputTypeTransportOrExitRegistration;
        RaceSimulatorLibraryDynamic::RegTransports regTransports = static_cast<RaceSimulatorLibraryDynamic::RegTransports>(userInputTypeTransportOrExitRegistration);

        if (regTransports < RaceSimulatorLibraryDynamic::RegTransports::_CompleteRegistration || regTransports > RaceSimulatorLibraryDynamic::RegTransports::_CarpetPlane)
            std::cout << "Ошибка! Введенное значение не соответствуте ни одному из заданных" << std::endl;

        if (regTransports == RaceSimulatorLibraryDynamic::RegTransports::_CompleteRegistration && race->GetArrTransports().size() < 2)
            std::cout << "\nВы не можете прервать процесс регистрации. Зарегистрировано менее 2 транспортных средств" << std::endl;

        else {
            switch (regTransports) {

            case RaceSimulatorLibraryDynamic::RegTransports::_CompleteRegistration:
                registrationCompleted = true;
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_AllTerrainBoots:
                if (TranspotIsAlreadyRegistered(race, "Ботинки-вездеходы"))
                    std::cout << "\nБотинки-вездеходы уже зарегистрированы!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* allTerrainBoots = new  RaceSimulatorLibraryDynamic::AllTerrainBoots;
                    if (race->AddTransport(allTerrainBoots)) {//если транспорт не является типом race 
                        std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                        delete allTerrainBoots;
                        allTerrainBoots = nullptr;
                    }
                    else
                        std::cout << "\n" << allTerrainBoots->GetNameTransport() << " успешно зарегистрирован!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_Broom:
                if (TranspotIsAlreadyRegistered(race, "Метла"))
                    std::cout << "\nМетла уже зарегистрирована!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* broom = new RaceSimulatorLibraryDynamic::Broom;
                    if (race->AddTransport(broom)) {//если транспорт не является типом race 
                        std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                        delete broom;
                        broom = nullptr;
                    }
                    else
                        std::cout << "\n" << broom->GetNameTransport() << " успешно зарегистрирован!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_Camel:
                if (TranspotIsAlreadyRegistered(race, "Верблюд"))
                    std::cout << "\nВерблюд уже зарегистрирован!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* camel = new RaceSimulatorLibraryDynamic::Camel;
                    if (race->AddTransport(camel)) {//если транспорт не является типом race 
                        std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                        delete camel;
                        camel = nullptr;
                    }
                    else
                        std::cout << "\n" << camel->GetNameTransport() << " успешно зарегистрирован!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_Centaur:
                if (TranspotIsAlreadyRegistered(race, "Кентавр"))
                    std::cout << "\nКентавр уже зарегистрирован!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* сentaur = new RaceSimulatorLibraryDynamic::Centaur;
                    if (race->AddTransport(сentaur)) {//если транспорт не является типом race 
                        std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                        delete сentaur;
                        сentaur = nullptr;
                    }
                    else
                        std::cout << "\n" << сentaur->GetNameTransport() << " успешно зарегистрирован!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_Eagle:
                if (TranspotIsAlreadyRegistered(race, "Орел"))
                    std::cout << "\nОрел уже зарегистрирован!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* eagle = new RaceSimulatorLibraryDynamic::Eagle;
                    if (race->AddTransport(eagle)) {//если транспорт не является типом race 
                        std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                        delete eagle;
                        eagle = nullptr;
                    }
                    else
                        std::cout << "\n" << eagle->GetNameTransport() << " успешно зарегистрирован!" << std::endl;
                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_CamelFast:
                if (TranspotIsAlreadyRegistered(race, "Верблюд-быстроход"))
                    std::cout << "\nВерблюд-быстроход уже зарегистрирован!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* camelFast = new RaceSimulatorLibraryDynamic::CamelFast;
                    if (race->AddTransport(camelFast)) {//если транспорт не является типом race 
                        std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                        delete camelFast;
                        camelFast = nullptr;
                    }
                    else
                        std::cout << "\n" << camelFast->GetNameTransport() << " успешно зарегистрирован!" << std::endl;

                }
                break;

            case RaceSimulatorLibraryDynamic::RegTransports::_CarpetPlane:
                if (TranspotIsAlreadyRegistered(race, "Ковер-самолет"))
                    std::cout << "\nКовер-самолет уже зарегистрирован!" << std::endl;
                else {
                    RaceSimulatorLibraryDynamic::ITransport* carpetPlane = new RaceSimulatorLibraryDynamic::CarpetPlane;
                    if (race->AddTransport(carpetPlane)) {//если транспорт не является типом race 
                        std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                        delete carpetPlane;
                        carpetPlane = nullptr;
                    }
                    else
                        std::cout << "\n" << carpetPlane->GetNameTransport() << " успешно зарегистрирован!" << std::endl;
                }


            }
        }

    }
}

//старт гонки, подсчет и вывод результатов
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

    //вывод результатов
    std::cout << "\nРезультаты гонки:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << resultArr[i]->GetNameTransport() << ". Время: " << resultArr[i]->RaceTime(distance) << std::endl;
    }

    //удаление временных векторов
    for (int i = 0; i < size; i++) {
        delete resultArr[i];
        resultArr[i] = nullptr;
    }
}

//меню: еще одна гонка/выход из программы
RaceSimulatorLibraryDynamic::OneMoreRaceOrExit MenuPlayOrExit() {
    unsigned userInput;

    while (true) {
        std::cout << "\n1. Провести еще одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;
        std::cout << "Выберите действие: ";

        std::cin >> userInput;
        RaceSimulatorLibraryDynamic::OneMoreRaceOrExit oneMoreRaceOrExit = static_cast<RaceSimulatorLibraryDynamic::OneMoreRaceOrExit>(userInput);

        if (oneMoreRaceOrExit <  RaceSimulatorLibraryDynamic::OneMoreRaceOrExit::OneMoreRace || oneMoreRaceOrExit > RaceSimulatorLibraryDynamic::OneMoreRaceOrExit::Exit) {
            std::cout << "Ошибка! Введено недопустимое значение" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            return oneMoreRaceOrExit;
    }
}

//очистка списка зарегистрированных ТС
void deleteTransports(RaceSimulatorLibraryDynamic::Race* raceType) {
    int size = raceType->GetArrTransports().size();
    for (int i = 0; i < size; i++) {
        raceType->GetArrTransports()[i] = nullptr;
    }
}

//реализация выбранной гонки
void RaceSelected(RaceSimulatorLibraryDynamic::Race* raceType) {
    setDistance(raceType); //установка дистанции

    while (regTransportOrStartRace(raceType) == RaceSimulatorLibraryDynamic::RegTransportOrStartRace::RegTransport) {
        RegTransport(raceType);
    }
    startRace(raceType);
    deleteTransports(raceType);
}
