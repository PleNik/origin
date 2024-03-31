#для проекта библиотеки
CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)

project(racing_lib VERSION 0.1 LANGUAGES CXX)#создал проект racing_lib

set (SOURCES
	AirRace.cpp
	AirTransport.cpp
	AllTerrainBoots.cpp
	Broom.cpp
	Camel.cpp
	CamelFast.cpp
	CarpetPlane.cpp
	Centaur.cpp
	Eagle.cpp
	GroundTransport.cpp
	ITransport.cpp
	LandAndAirRace.cpp
	LandRace.cpp
	Race.cpp
)

set (HEADERS
	AirRace.h
	AirTransport.h
	AllTerrainBoots.h
	Broom.h
	Camel.h
	CamelFast.h
	CarpetPlane.h
	Centaur.h
	Eagle.h
	Enums.h
	GroundTransport.h
	ITransport.h
	LandAndAirRace.h
	LandRace.h
	Race.h
)

add_library(race_lib SHARED ${SOURCES} ${HEADERS})
