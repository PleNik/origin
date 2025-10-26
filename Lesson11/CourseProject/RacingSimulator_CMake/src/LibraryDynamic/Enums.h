#pragma once

namespace RaceSimulatorLibraryDynamic {
    //тип гонки
    enum class RaceType {
        LandRace = 1,
        AirRace,
        LandAndAirRace
    };

    //меню зарегистрировать ТС/начать гонку
    enum class RegTransportOrStartRace {
        RegTransport = 1,
        StartRace
    };

    //меню регистрации транспортных средств
    enum class RegTransports {
        _CompleteRegistration,	//закончить регистрацию
        _AllTerrainBoots,		//ботинки-вездеходы
        _Broom,					//метла
        _Camel,					//верблюд
        _Centaur,				//кентавр
        _Eagle,					//орел
        _CamelFast,		    	//верблюд-быстроход
        _CarpetPlane			//ковер-самолет
    };

    //тип транспорта
    enum class TransportType {
        Ground,
        Air
    };

    //меню: еще одна гонка/выход
    enum class OneMoreRaceOrExit {
        OneMoreRace = 1,
        Exit
    };
}
