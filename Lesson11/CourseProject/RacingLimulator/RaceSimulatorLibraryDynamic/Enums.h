#pragma once

namespace RaceSimulatorLibraryDynamic {
    //��� �����
    enum class RaceType {
        LandRace = 1,
        AirRace,
        LandAndAirRace
    };

    //���� ���������������� ��/������ �����
    enum class RegTransportOrStartRace {
        RegTransport = 1,
        StartRace
    };

    //���� ����������� ������������ �������
    enum class RegTransports {
        _CompleteRegistration,	//��������� �����������
        _AllTerrainBoots,		//�������-���������
        _Broom,					//�����
        _Camel,					//�������
        _Centaur,				//�������
        _Eagle,					//����
        _CamelFast,		    	//�������-���������
        _CarpetPlane			//�����-�������
    };

    //��� ����������
    enum class TransportType {
        Ground,
        Air
    };

    //����: ��� ���� �����/�����
    enum class OneMoreRaceOrExit {
        OneMoreRace = 1,
        Exit
    };
}
