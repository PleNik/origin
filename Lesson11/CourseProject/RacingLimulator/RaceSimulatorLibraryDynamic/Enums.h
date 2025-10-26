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
        _CompleteRegistration,	//çàêîí÷èòü ðåãèñòðàöèþ
        _AllTerrainBoots,		//áîòèíêè-âåçäåõîäû
        _Broom,					//ìåòëà
        _Camel,					//âåðáëþä
        _Centaur,				//êåíòàâð
        _Eagle,					//îðåë
        _CamelFast,		    	//âåðáëþä-áûñòðîõîä
        _CarpetPlane			//êîâåð-ñàìîëåò
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
