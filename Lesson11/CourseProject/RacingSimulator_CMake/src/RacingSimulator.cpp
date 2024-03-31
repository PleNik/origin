#include "Functions.h"

int main() {

    setlocale(LC_ALL, "ru");

    std::cout << "Добро пожаловать в гоночный симулятор! " << std::endl;

    do {
        RaceSimulatorLibraryDynamic::RaceType raceType = SelectRaceType();

        if (raceType == RaceSimulatorLibraryDynamic::RaceType::LandRace) {
            RaceSimulatorLibraryDynamic::LandRace landRace;
            RaceSelected(&landRace);
        }
        else if (raceType == RaceSimulatorLibraryDynamic::RaceType::AirRace) {
            RaceSimulatorLibraryDynamic::AirRace airRace;
            RaceSelected(&airRace);
        }
        else {
            RaceSimulatorLibraryDynamic::LandAndAirRace landAndRace;
            RaceSelected(&landAndRace);
        }
    } while (MenuPlayOrExit() == RaceSimulatorLibraryDynamic::OneMoreRaceOrExit::OneMoreRace);
    

    return 0;
}