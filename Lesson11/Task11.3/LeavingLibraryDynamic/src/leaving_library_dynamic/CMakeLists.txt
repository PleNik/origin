#для проекта библиотеки
CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)
project(leaving_lib VERSION 0.1 LANGUAGES CXX)#создал проект leaving_lib
set(leaving_lib_source DynamicLeaving.h DynamicLeaving.cpp)#из этих файлов я буду создавать динамическую библиотеку
add_library(leav_lib SHARED ${leaving_lib_source})#библиотека leav_lib будет динамическая,
#и она будет собираться из файлов, указанных в переменной leaving_lib_source