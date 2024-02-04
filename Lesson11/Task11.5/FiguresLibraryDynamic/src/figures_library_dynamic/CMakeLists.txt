#для проекта библиотеки
CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)

project(figures_lib VERSION 0.1 LANGUAGES CXX)#создал проект figures_lib

set(figures_lib_source equilateralTriangle.h equilateralTriangle.cpp figure.h figure.cpp isoscelesTriangle.h isoscelesTriangle.cpp parallelogram.h parallelogram.cpp
quadrilateral.h quadrilateral.cpp rectangle.h rectangle.cpp rhombus.h rhombus.cpp rightTriangle.h rightTriangle.cpp rightTriangle.h. rightTriangle.cpp square.h square.cpp
triangle.h triangle.cpp) #из этих файлов я буду создавать динамическую библиотеку

add_library(figur_lib SHARED ${figures_lib_source})#библиотека leav_lib будет динамическая,
#и она будет собираться из файлов, указанных в переменной leaving_lib_source